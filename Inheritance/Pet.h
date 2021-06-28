#pragma once
#include <iostream>

struct Pet
{
    Pet(const std::string &);
    std::string m_name;
};

struct Dog : Pet
{
    Dog(const std::string &);
    std::string bark();
};

