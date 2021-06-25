#include <iostream>

struct People {
    People(const std::string);
    void setName(const std::string);
    const std::string getName();

    std::string m_name;
};