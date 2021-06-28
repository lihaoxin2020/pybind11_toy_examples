#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

struct PolymorphicPet {
    virtual ~PolymorphicPet() = default;
};

struct PolymorphicDog : PolymorphicPet {
    std::string bark() const { return "woof!"; }
};

// Same binding code
PYBIND11_MODULE(PolyPet, m) {
    py::class_<PolymorphicPet>(m, "PolyPet");
    py::class_<PolymorphicDog, PolymorphicPet>(m, "PolyDog")
        .def(py::init<>())
        .def("bark", &PolymorphicDog::bark);

    // Again, return a base pointer to a derived instance
    m.def("pet_store2", []() { return std::unique_ptr<PolymorphicPet>(new PolymorphicDog); });
    // this will automatically downcast and return "PolymorphicDog" in Python
}