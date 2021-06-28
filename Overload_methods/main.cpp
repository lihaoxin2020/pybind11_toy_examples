#include <pybind11/pybind11.h>
#include "Overload.h"

namespace py = pybind11;

PYBIND11_MODULE(Overload, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        .def("set", py::overload_cast<int>(&Pet::set), "Set the pet's age")
        .def("set", py::overload_cast<const std::string &>(&Pet::set), "Set the pet's name")
        .def_readwrite("name", &Pet::m_name)
        .def_readwrite("age", &Pet::m_age);
}