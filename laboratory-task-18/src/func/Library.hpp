#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <map>
#include <string>
#include "Book.hpp"

class Library {
private:
    std::map<std::string, Book> books; // ключ - ISBN, значение - объект Book

public:
    Library() = default;
    Library(std::map<std::string, Book>);
    Library(const Library&);
    ~Library(){};

    void addBook(const Book& book);
    Book& findBook(const std::string& isbn);
    bool removeBook(const std::string& isbn);
    void viewBooks() const;

    bool addAuthor(const std::string& isbn, const std::string& author);
    bool removeAuthor(const std::string& isbn, const std::string& author);

    void sortBooksByTitle();
    void sortBooksByISBN();

    friend std::ostream& operator<<(std::ostream&,const Library&);

};

#endif // LIBRARY_HPP

