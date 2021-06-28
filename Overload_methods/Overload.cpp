#include "Overload.h"

Pet::Pet(const std::string &name, int age) {
    m_name = name;
    m_age = age;
}

void Pet::set(const std::string &name) {
    m_name = name;
}

void Pet::set(int age) {
    m_age = age;
}

