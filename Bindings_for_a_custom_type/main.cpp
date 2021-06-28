#include <pybind11/pybind11.h>
#include "People.h"

namespace py = pybind11;

PYBIND11_MODULE(Human, m) {  // name of the Python module
    py::class_<People>(m, "People", py::dynamic_attr())     // creates bindings for a c++ class or struct-style data structure
                                                            // by "py::dynamic_attr()" we can dynamically add new attribute to an instance; otherwise
                                                            // adding attribute dynamically in Python will cause error. 
        .def(py::init<std::string &, int &>())      // take in types of constructor's params and wraps the corresponding constructor
        .def("setName", &People::setName)   // expose func entrance in Python library
        .def("getName", &People::getName)   //
        .def_readwrite("name", &People::m_name)     // expose "m_name" field for read or write to Python and named it as "name"
        .def_property("age", &People::getAge, &People::setAge)      // make private c++ field to normal Python interface
        .def("__repr__",    // binding lambda function for valid Python repr() output; otherwise, built in invalid string is returned
            [](const People &a) {
                return "<Human.People named '" + a.m_name + "'>";
            }
        );
}