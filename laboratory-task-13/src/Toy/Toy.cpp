
#include <iostream>
#include <string>
#include "Toy.h"

//Конструкторы
Toy::Toy() : name(""), age(0) {}

Toy::Toy(const std::string & newName, int32_t newAge): name(newName), age(newAge)
{
}

Toy::Toy(const Toy& rhs):name(rhs.name), age(rhs.age)
{
}

//Присваивание
Toy &Toy::operator=(const Toy & rhs)
{
    if(this != &rhs)
    {
        age = rhs.age;
        name = rhs.name;
    }
    return *this;
}

// Методы доступа (геттеры и сеттеры)
void Toy::setName(const std::string& newName) 
{
     name = newName;
}

std::string Toy::getName() const
{
     return name;      
}

void Toy::setAge(int newAge) 
{
     age = newAge;
}

int Toy::getAge() const 
{
     return age; 
}

// Метод для вывода информации о игрушке
std::ostream& operator<<(std::ostream& out, const Toy& rhs)  
{
     out << "Name: " << rhs.name << ", Age: " << rhs.age << '\n';
     return out;
}


std::istream& operator>>(std::istream& in, Toy& rhs)
{
    std::cout << "Enter name:";
    in >> rhs.name;
    std::cout << "Enter age restriction:";
    in >> rhs.age;
    return in;
}

//Опрератор сравнения
bool Toy::operator==(const Toy& rhs) const 
{
     return (this->name == rhs.name && this->age == rhs.age);
}