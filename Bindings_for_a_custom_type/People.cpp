#include "People.h"

People::People(std::string name) {
    People::setName(name);
}

void People::setName(std::string name) {
    People::m_name = name;
}

const std::string People::getName() {
    return People::m_name;
}
