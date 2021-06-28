#include <iostream>

struct People {
public:
    People(std::string &, int);
    void setAge(int);
    int getAge();

    void setName(std::string);
    std::string getName();

    std::string m_name;
private:
    int m_age;
};