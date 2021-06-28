#include <pybind11/pybind11.h>
#include "Enum.h"

namespace py = pybind11;

PYBIND11_MODULE(Enum, m) {
    py::class_<Pet> pet(m, "Pet");

    pet.def(py::init<const std::string &, Pet::Kind>())
        .def_readwrite("name", &Pet::m_name)
        .def_readwrite("type", &Pet::m_type);

    py::enum_<Pet::Kind>(pet, "Kind")
        .value("Dog", Pet::Kind::Dog)
        .value("Cat", Pet::Kind::Cat)
        .export_values();   // exports enum entires into parent scope
}