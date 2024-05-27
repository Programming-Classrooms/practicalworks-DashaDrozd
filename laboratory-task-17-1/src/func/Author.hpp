#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <string>
#include <iostream>

class Author {
private:
    std::string lastName; //Фамилия
    std::string firstName; //Имя
    std::string middleName; //Отчество

public:
    //Конструкторы 
    Author() = default; // по умолчанию
    Author(std::string, std::string, std::string); //с параметром
    ~Author() = default; // деструктор

    Author& operator=(const Author&); // оператор присваивания

    //Геттеры
    std::string getLastName() const; 
    std::string getFirstName() const;
    std::string getMiddleName() const;

    bool operator==(const Author& ) const; //перегрузка оператора сравнения

    friend std::ostream& operator<<(std::ostream&, const Author&); //перегрузка оператора вывода
    friend std::istream& operator>>(std::istream&, Author&); //перегрузка оператора ввода
};

#endif // AUTHOR_HPP
