#ifndef AUTHORLIST_HPP
#define AUTHORLIST_HPP

#include <vector>
#include <iostream>

#include "Author.hpp"

class AuthorList {
private:
    std::vector<Author> authors; // вектор для хранения авторов

public:
    AuthorList() = default; //конструктор по умолчанию
    AuthorList(std::vector<Author>); //конструктор копирования
    ~AuthorList(){} //деструктор

    void addAuthor(const Author&); //добавление автора
    void removeAuthor(const Author&);// удаление автора

    Author& findAuthorByLastName(const std::string&); // поиск автора по фамилии

    //Геттеры
    size_t getAuthorCount() const; //количество авторов
    const Author& getAuthor(size_t) const; //получение определенного автора по индексу
    const std::vector<Author>& getAuthors() const ; // получение вектора авторов

    
    bool operator==(const AuthorList&) const; // перегрузка оператора сравнения

    friend std::ostream& operator<<(std::ostream&, const AuthorList&); // перегрузка оператора вывода
    friend std::istream& operator>>(std::istream&, AuthorList&); //перегрузка оператора ввода
};

#endif // AUTHORLIST_HPP
