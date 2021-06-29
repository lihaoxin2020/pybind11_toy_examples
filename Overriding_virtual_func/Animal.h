#pragma once
#include <iostream>

class Animal {
public:
    virtual ~Animal() { }
    virtual std::string go(int n_times) = 0;
};

class Dog : public Animal {
public:
    std::string go(int) override;
};

/* trampoline */
class PyAnimal : public Animal {
public:
    /* Inherit the constructors */
    using Animal::Animal;

    std::string go(int) override;
};

std::string call_go(Animal *);