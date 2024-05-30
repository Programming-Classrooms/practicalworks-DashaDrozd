#ifndef  CARRIAGE_HPP
#define CARRIAGE_HPP
#include <iostream>
#include "src/Stack/Stack.hpp"

enum class Color { 
    RED,
    GREEN,
    };

class Carriage {
private:
    Color colorCarriage;

public:
//Конструкторы
    Carriage();//по умолчанию
    Carriage(Color initColor); //с параметрами
    Carriage(const Carriage &rhs);// копирования
    ~Carriage(){}; //деструктор

//Перегрузка оператора присваивания
    Carriage& operator=(Carriage&rhs);

    Color getColor() const;// получение цвета

    friend std::istream& operator>>(std::istream& in, Carriage& rhs); // ввод
    friend std::ostream& operator<<(std::ostream& out, const Carriage& rhs); //вывод
};
#endif // !1
