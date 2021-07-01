#include <iostream>
#include <pybind11/pybind11.h>

class Animal {
public:
    virtual std::string go(int n_times) = 0;
    virtual std::string name() { return "unknown"; }
};
class Dog : public Animal {
public:
    std::string go(int n_times) override {
        std::string result;
        for (int i=0; i<n_times; ++i)
            result += bark() + " ";
        return result;
    }
    virtual std::string bark() { return "woof!"; }
};

// class PyAnimal : public Animal {
// public:
//     using Animal::Animal; // Inherit constructors
//     std::string go(int n_times) override { PYBIND11_OVERRIDE_PURE(std::string, Animal, go, n_times); }
//     std::string name() override { PYBIND11_OVERRIDE(std::string, Animal, name, ); }
// };

// class PyDog : public Dog {
// public:
//     using Dog::Dog; // Inherit constructors
//     std::string go(int n_times) override { PYBIND11_OVERRIDE(std::string, Dog, go, n_times); }
//     std::string name() override { PYBIND11_OVERRIDE(std::string, Dog, name, ); }    // Although the c++ Dog class does not overrides name() from Animal, 
//                                                                                     // it is still required to override in its tampoline class. 
//     std::string bark() override { PYBIND11_OVERRIDE(std::string, Dog, bark, ); }    // Override added bark()
// };


// Alternative method: 
template <class AnimalBase = Animal> class PyAnimal : public AnimalBase {
public:
    using AnimalBase::AnimalBase; // Inherit constructors
    std::string go(int n_times) override { PYBIND11_OVERRIDE_PURE(std::string, AnimalBase, go, n_times); }
    std::string name() override { PYBIND11_OVERRIDE(std::string, AnimalBase, name, ); }
};

template <class DogBase = Dog> class PyDog : public PyAnimal<DogBase> {
public:
    using PyAnimal<DogBase>::PyAnimal; // Inherit constructors
    // Override PyAnimal's pure virtual go() with a non-pure one:
    std::string go(int n_times) override { PYBIND11_OVERRIDE(std::string, DogBase, go, n_times); }
    std::string bark() override { PYBIND11_OVERRIDE(std::string, DogBase, bark, ); }
    // No need to override name() is it is not overrode in c++ class
};

namespace py = pybind11;

PYBIND11_MODULE(Combine, m) {
    py::class_<Animal, PyAnimal<>> animal(m, "Animal");
    animal.def(py::init<>())
        .def("go", &Animal::go)
        .def("name", &Animal::name);
    py::class_<Dog, Animal, PyDog<>> dog(m, "Dog");
    dog.def(py::init<>())
        .def("bark", &Dog::bark);
}

// If you are defining a custom constructor in a derived Python class, you must ensure that you explicitly 
// call the bound C++ constructor using __init__, regardless of whether it is a default constructor or not.
// eg. 
// class Cat(Dog):
//  def __init__(self):
//      Dog.__init__(self)  <- this line is necessary, or type error will be thrown
//      ...