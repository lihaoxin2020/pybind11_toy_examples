#pragma once
#include <iostream>

struct Pet {
    enum Kind {
        Dog = 0,
        Cat
    };

    Pet(const std::string &, Kind);

    std::string m_name;
    Kind m_type;
};