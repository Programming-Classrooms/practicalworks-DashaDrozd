#include "Book.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

size_t Book::counter = 0;

//Конструктор с параметрами
Book::Book(const std::string initTitle, const std::vector<std::string> initAuthors, double initPrice, int32_t initCount): ISBN(std::to_string(++counter)), title(initTitle), authors(initAuthors), price(initPrice), count(initCount) {}

//Конструктор по умолчанию
Book::Book(): ISBN(std::to_string(++counter)), title(" "), price(0.0), count(0) {}

//Конструктор копирования
Book::Book(const Book&rhs):ISBN(rhs.ISBN), title(rhs.title), price (rhs.price), count (rhs.count), authors(rhs.authors)
{}

//Перегрузка оператора присваивания
Book &Book::operator=(const Book &rhs)
{
    if(this != &rhs)
    {
        title = rhs.title;
        price = rhs.price;
        count = rhs.count;
        authors = rhs.authors;
        ISBN = rhs.ISBN;
    }

    return *this;
}

//Геттеры
std::string Book::getTitle() const
{
    return title;
}

std::string Book::getISBN() const
{
    return ISBN;
}

//Добавление автора
void Book::addAuthor(const std::string& author) {
    authors.push_back(author);
}

//Удаление автора
void Book::removeAuthor(const std::string& author) {
    authors.erase(std::remove(authors.begin(), authors.end(), author), authors.end());
}

//Функция печати
void Book::print(std::ostream &out) const
{
    out << *this;
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Book& rhs) {
    out << "ISBN: " << rhs.ISBN << "\nTitle: " << rhs.title << "\nAuthors: ";
    for (std::string author : rhs.authors) {
        out << author << " ";
    }
    out << "\n Price: " << rhs.price << "\nCount: " << rhs.count << std::endl;
    out << "///////////////////////////////////////////////////////\n";

    return out;
}

//Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, Book& rhs)
{
   std::cout << "Enter title of book: ";
    std::getline(in, rhs.title);

    size_t num = 0;
    std::cout << "Enter number of authors: ";
    in >> num;
    in.ignore();

    rhs.authors.clear();
    std::string author;
    for (size_t i = 0; i < num; ++i) {
        std::cout << "Enter an author's name: ";
        std::getline(in, author);
        rhs.authors.push_back(author);
    }

    std::cout << "Enter a price of book: ";
    in >> rhs.price;
    std::cout << "Enter number of books: ";
    in >> rhs.count;
    in.ignore(); 

    return in;
}