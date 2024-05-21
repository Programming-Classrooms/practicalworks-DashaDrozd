#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <sstream
#include <utility>

struct Author
{
    std::string lastName;
    std::string firstName;
    std::string middleName;

   bool operator<(const Author& other) const {
        if (lastName != other.lastName) {
            return lastName < other.lastName;
        }
        if (firstName != other.firstName) {
            return firstName < other.firstName;
        }
        return middleName < other.middleName;
    }
};

class Book
{
private:
    int32_t UDK;
    std::set<Author> authors;
    std::string name;
    int32_t year;

public:
    Book() = default;
    Book(int32_t, std::set<Author>, std::string, int32_t);
    Book(const Book&);
    Book& operator=(const Book&);
    void addAuthor(const Author&);
    void deleteAuthor(const Author&);
    ~Book(){};
};

#endif