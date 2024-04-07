#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <string>

class Toy {
private:
    std::string name;
    int32_t age;
public:
    // Конструкторы
    Toy();
    Toy(const std::string&, int32_t);
    Toy(const Toy&) ;

    //Присваивание
    Toy& operator=(const Toy&);

    // Методы доступа (геттеры и сеттеры)
    void setName(const std::string&);
    std::string getName() const;

    void setAge(int );
    int32_t getAge() const ;

    // Методы для вывода и ввода информации о игрушке
    friend std::ostream& operator<<(std::ostream&, const Toy&);
    friend std::istream& operator>>(std::istream&, Toy&);
    
    bool operator==(const Toy&) const;
};
#endif// DEBUG