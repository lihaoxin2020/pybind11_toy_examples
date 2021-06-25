#include <pybind11/pybind11.h>
#include "func.h"

namespace py = pybind11;

PYBIND11_MODULE(func, m) {  // "func" is the name of Python import module
    m.doc() = "pybind11 hello_world";
    m.def("add", &add, "A function which adds two numbers");
}