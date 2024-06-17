#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

#include "../func/Author.hpp"
#include "../func/AuthorList.hpp"


class Book
{
private:
    size_t UDK; //УДК
    AuthorList authors; //авторы
    std::string name; //название
    size_t year; //год выпуска

public:
    //Конструкторы
    Book() = default; // по умолчанию
    Book(int32_t, AuthorList, std::string, int32_t); // с параметрами
    Book(const Book&); // копирования
    ~Book(){}; // деструктор

    Book& operator=(const Book&); // перегрузка оператора приваивания

    //Геттеры
    std::string getName() const;    
    AuthorList getAuthors() const;

    //Перегрузка операторов сравнения
    bool operator==(const Book&) const;
    bool operator!=(const Book&) const;

    void addAuthor(const Author&); // добавление автора
    void deleteAuthor(const Author&); //удаление автора

    friend std::istream& operator>>(std::istream&, Book&); // перегрузка оператора ввода
    friend std::ostream& operator<<(std::ostream&, const Book&); // перегрузка оператора вывода
  
};

#endif
