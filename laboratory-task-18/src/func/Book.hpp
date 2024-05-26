#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <vector>

class Book {
private:
    std::string ISBN; //Идентификационный номер - уникальное текстовое поле
    std::string title; // Название
    std::vector<std::string> authors; //Список авторов
    double price; //Цена
    int32_t count; //Количество экземпляров
    static size_t counter; //статическая переменная для ИСБН

public:
    //Конструкторы
    Book(); //по умолчанию
    Book(const std::string, const std::vector<std::string>, double, int32_t); //с парметром
    Book(const Book&); //копирования

    Book& operator=(const Book&); //перегрузка оператора присваивания

    std::string getTitle() const; //получение названия
    std::string getISBN() const; // получение номера

    //Сеттеры
    void setPrice(double); 
    void setCount(int32_t);

    void addAuthor(const std::string&); // добавление автора
    void removeAuthor(const std::string&); // удаление автора

    friend std::ostream& operator<<(std::ostream&, const Book&); //перегрузка оператора вывода
    friend std::istream& operator>>(std::istream&, Book&); // перегрузка оператора ввода

    void print(std::ostream&) const;
};

#endif // BOOK_HPP
