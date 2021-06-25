#include <pybind11/pybind11.h>
#include "People.h"

namespace py = pybind11;

PYBIND11_MODULE(Human, m) {  // name of the Python module
    py::class_<People>(m, "People")  // creates bindings for a c++ class or struct-style data structure
        .def(py::init<std::string &>())  // take in types of constructor's params and wraps the corresponding constructor
        .def("setName", &People::setName)
        .def("getName", &People::getName);
}