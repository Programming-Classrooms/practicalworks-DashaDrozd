#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include<algorithm>
#include <iostream>

#include "Book.hpp"

class Library
{
 private:
    std::vector <Book> books;//Вектор для хранения книг

 public:
   //Конструкторы
    Library() = default; //по умолчанию
    Library(std::vector<Book>); //с параметром
    ~Library(){}; //деструктор

    Library& operator=(const Library&); // перегрузка оператора присваивания
    void addBook(const Book&); //добавление книги
    void deleteBook(const Book&); //удаление книги
    void searchByName(std::string); //поиск по имени
    void searchByAuthor(Author); //поиск по автору
    

    friend std::ostream& operator<<(std::ostream&, const Library&); //перегрузка оператора вывода
    friend std::istream& operator>>(std::istream&, Library&); //перегрузка оператора ввода
};

#endif
