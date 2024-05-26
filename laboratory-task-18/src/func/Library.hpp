#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <map>
#include <string>

#include "Book.hpp"

class Library {
private:
    std::map<std::string, Book> books; // ключ - ISBN, значение - объект Book

public:
    //Конструкторы
    Library() = default; //по умолчанию
    Library(std::map<std::string, Book>); //с параметром
    Library(const Library&); //копирования
    ~Library(){}; //деструктрр

    void addBook(const Book& book); //добавление книги
    Book& findBook(const std::string& isbn); //поиск книги по ИСБН
    bool removeBook(const std::string& isbn); //удаление книги по ИСБН
    void viewBooks() const; //просмотор списка книг

    bool addAuthor(const std::string& isbn, const std::string& author); // добавление автора по ИСБН
    bool removeAuthor(const std::string& isbn, const std::string& author); // удаление автора по ИСБН

    void sortBooksByTitle(); // сортировка по названию
    void sortBooksByISBN(); //сортировка по ИСБН

    friend std::ostream& operator<<(std::ostream&,const Library&); // перегрузка оператора вывода

};

#endif // LIBRARY_HPP
