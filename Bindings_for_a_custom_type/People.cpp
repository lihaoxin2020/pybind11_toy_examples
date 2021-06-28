#include "People.h"

People::People(std::string &name, int age) {
    setName(name);
    setAge(age);
}

void People::setName(std::string name) {
    m_name = name;
}

std::string People::getName() {
    return m_name;
}

void People::setAge(int age) {
    m_age = age;
}

int People::getAge() {
    return m_age;
}
