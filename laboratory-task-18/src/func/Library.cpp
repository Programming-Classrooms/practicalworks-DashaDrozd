#include "Library.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

//Конструктор с параметром
Library::Library(std::map<std::string, Book> initBooks): books(initBooks)
{
}

//Конструктор копирования
Library::Library(const Library &rhs):books(rhs.books)
{
}

//Добавление книги
void Library::addBook(const Book &book)
{
    books[book.getISBN()] = book;
}

//Поиск книги по ИСБН
Book& Library::findBook(const std::string& isbn) {
    size_t counter = 0;
    for(auto &pair: books)
    {
        if(pair.first == isbn)
        {
            ++counter;
            return pair.second;
        }
    }

    if(counter == 0)
    {
        throw std::runtime_error("Such book is not found!\n");
    }
    
}

//Удаление книги по ИСБН
bool Library::removeBook(const std::string& isbn) {
    return books.erase(isbn);
}

//Просмотр списка книг
void Library::viewBooks() const {
    for (const auto& pair : books) {
        std::cout << pair.second << " ";
    }
}

//Добавление автора по ИСБН
bool Library::addAuthor(const std::string& isbn, const std::string& author) {
   for(auto& pair: books)
   {
        if(pair.first == isbn)
        {
            pair.second.addAuthor(author);
            return true;
        }
   }

   return false;
}

//Удаление автора по ИСБН
bool Library::removeAuthor(const std::string& isbn, const std::string& author) {
   for(auto& pair: books)
   {
        if(pair.first == isbn)
        {
            pair.second.removeAuthor(author);
            return true;
        }
   }

    return false;
}


//Сортировка по названию
void Library::sortBooksByTitle() {
    std::vector<Book> bookList;
    for (const auto& pair : books) {
        bookList.push_back(pair.second);
    }

    std::sort(bookList.begin(), bookList.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });

    for (const auto& book : bookList) {
        std::cout << book << " ";
    }
}


//Сортировка по ИЗБН
void Library::sortBooksByISBN()
{
     std::vector<Book> bookList;
    for (const auto& pair : books) {
        bookList.push_back(pair.second);
    }

    std::sort(bookList.begin(), bookList.end(), [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });

    for (const auto& book : bookList) {
        book.print(std::cout);
        std::cout << " ";
    }
}


//Перегрузка оператора вывода
std::ostream &operator<<(std::ostream &out, const Library &rhs)
{
    for (const auto& pair : rhs.books) {
        out << pair.second << "\n";
    }

    out << std::endl;

    return out;
}
