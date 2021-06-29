#include "Animal.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(Override, m) {
    py::class_<Animal, PyAnimal /* <--- trampoline*/>(m, "Animal")
        .def(py::init<>())
        .def("go", &Animal::go);

    py::class_<Dog, Animal>(m, "Dog")
        .def(py::init<>());

    m.def("call_go", &call_go);
}