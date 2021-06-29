#include "Animal.h"
#include <pybind11/pybind11.h>

std::string Dog::go(int n_times) {
    std::string result;
    for (int i=0; i<n_times; ++i)
        result += "woof! ";
    return result;
}

std::string call_go(Animal *animal) {
    return animal->go(3);
}

/* Trampoline (need one for each virtual function) */
std::string PyAnimal::go(int n_times) {
    PYBIND11_OVERRIDE_PURE(
        std::string, /* Return type */
        Animal,      /* Parent class */
        go,          /* Name of function in C++ (must match Python name) */
        n_times      /* Argument(s) */
    );
}
