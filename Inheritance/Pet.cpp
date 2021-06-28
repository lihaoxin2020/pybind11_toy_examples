#include "Pet.h"

Pet::Pet(const std::string &name) {
    m_name = name;
}

Dog::Dog(const std::string &name) : Pet::Pet(name) {}

std::string Dog::bark() {
    return "woof!";
}