#include "Carriage.hpp"
#include <string>
#include "src/Stack/Stack.hpp"

//********************************************Конструкторы********************************************************************
Carriage::Carriage():colorCarriage(Color::GREEN)
{
}

Carriage::Carriage(Color initColor):colorCarriage(initColor)
{
}

Carriage::Carriage(const Carriage &rhs): colorCarriage(rhs.colorCarriage)
{
}

//Перегрузка присваивания
Carriage &Carriage::operator=(Carriage &rhs)
{
    if(this != &rhs)
    {
        colorCarriage = rhs.colorCarriage;
    }

    return *this;
}

//геттер
Color Carriage::getColor() const
{
    return this->colorCarriage;
}

//ввод
std::istream &operator>>(std::istream &in, Carriage &rhs)
{
  std::string color;
  std::cout << "Enter color of carriage: ";
  in >> color;

  if(color == "green")
  {
    rhs.colorCarriage = Color::GREEN;
  } 

    if(color == "red")
  {
    rhs.colorCarriage = Color::RED;
  } 

  return in;
}

//вывод
std::ostream &operator<<(std::ostream &out, const Carriage &rhs)
{
    switch(rhs.colorCarriage)
    {
        case Color::GREEN:
            out << "Green carriage\n";
            break;
        case Color::RED:
             out << "Red carriage\n";
            break;
    }

    return out;
}
