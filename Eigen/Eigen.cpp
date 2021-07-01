#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <Eigen/Dense>

class MyClass {
    Eigen::MatrixXd big_mat = Eigen::MatrixXd::Zero(10000, 10000);
public:
    Eigen::MatrixXd &getMatrix() { return big_mat; }
    const Eigen::MatrixXd &viewMatrix() { return big_mat; }
};

namespace py = pybind11;

// Later, in binding code:
PYBIND11_MODULE(Eigen, m) {
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("copy_matrix", &MyClass::getMatrix) // Makes a copy!
        .def("get_matrix", &MyClass::getMatrix, py::return_value_policy::reference_internal)    // read/write. no copy
        .def("view_matrix", &MyClass::viewMatrix, py::return_value_policy::reference_internal); // readable. no copy
};