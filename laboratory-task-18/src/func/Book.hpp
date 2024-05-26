#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <vector>

class Book {
private:
    std::string ISBN;
    std::string title;
    std::vector<std::string> authors;
    double price;
    int32_t count;
    static size_t counter;

public:
    Book();
    Book(const std::string, const std::vector<std::string>, double, int32_t);
    Book(const Book&);

    Book& operator=(const Book&);

    std::string getTitle() const;
    std::string getISBN() const;

    void addAuthor(const std::string&);
    void removeAuthor(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);

    void print(std::ostream&) const;
};

#endif // BOOK_HPP
