#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Person
{
    private:
        std::string _name;
        unsigned int _age;
    public:
        Person(std::string n, unsigned int a): _name(n), _age(a){}
        bool operator>(Person &rhs)
        {
            return this->_age > rhs._age;
        }
        bool operator<(Person &rhs)
        {
            return rhs > *this;
        }
        bool operator==(Person &rhs)
        {
            return this->_age == rhs._age;
        }
        friend std::ostream& operator<<(std::ostream& os, const Person& dt);
};

std::ostream& operator<<(std::ostream& os, const Person& dt)
{
    os << "Name : " << std::setw(10) << dt._name << "| Age : " << dt._age;
    return os;
}

#endif