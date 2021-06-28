#include <iostream>

struct Pet {
    Pet(const std::string &, int);

    void set(int);
    void set(const std::string &);
    // bind Pet::set will cause error since the compiler does not know which mothod the user intended to select. 
    // This is avoided by casting them to function pointers.

    std::string m_name;
    int m_age;
};