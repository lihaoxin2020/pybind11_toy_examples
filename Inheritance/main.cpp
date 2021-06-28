#include <pybind11/pybind11.h>
#include "Pet.h"

namespace py = pybind11;

// Method 1: inheritance template
// PYBIND11_MODULE(Pet, m) {
//     py::class_<Pet>(m, "Pet")
//         .def(py::init<const std::string &>())
//         .def_readwrite("name", &Pet::m_name);
    
//     py::class_<Dog, Pet /* c++ parent type */>(m, "Dog")
//         .def(py::init<const std::string &>())
//         .def("bark", &Dog::bark);
// }

// Method 2: inheritance template
PYBIND11_MODULE(Pet, m) {
    py::class_<Pet> pet(m, "Pet");  // assign a name to class_ bounded object
    pet.def(py::init<const std::string &>())
       .def_readwrite("name", &Pet::m_name);
    
    py::class_<Dog>(m, "Dog", pet /* named python parent type */)
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);
    
    // both methods work as regular non-polymorphic types with inheritance relationship.
    m.def("pet_store", []() {return std::unique_ptr<Pet>(new Dog("Plato"));});
    // return "Dog" instance behind "Pet" pointer, remain "Pet" in Python
}
