#include "Book.hpp"

Book::Book(int32_t initUDK, std::set<Author> initAuthors, std::string initName, int32_t initYear): UDK(initUDK), authors(initAuthors), name(initName), year(initYear)
{
}

Book::Book(const Book &rhs): UDK(rhs.UDK), authors(rhs.authors), name(rhs.name), year(rhs.year)
{
}

Book &Book::operator=(const Book &rhs)
{
     if(this!=&rhs)
     {
        UDK = rhs.UDK;
        name = rhs.name;
        year = rhs.year;
        authors = std::move(rhs.authors);

     }

}

void Book::addAuthor(const Author &other)
{
    authors.push_back(other);
}

void Book::deleteAuthor(const Author &other)
{
    authors.pop_back(other);
}

std::istream& operator>>(std::istream& fin, Book& rhs)
{
    std::string line;
    std::getline(fin, line, ';');
    rhs.UDK = std::stoi(line);
    std::getline(fin, line, ';');
    rhs.name = line;
    std::getline(fin, line, ';');
    rhs.year = std::stoi(line);

    rhs.authors.clear();
    while (std::getline(fin, line, ',')) {
        std::istringstream iss(line);
        std::string lastName, firstName, middleName;
        std::getline(iss, lastName, ' ');
        std::getline(iss, firstName, ' ');
        std::getline(iss, middleName);
        rhs.authors.emplace_back(lastName, firstName, middleName);
    }
    return fin;
}

std::ostream& operator<<(std::ostream& out, const Book& rhs)
{
    out << rhs.UDK <<'\n';
    out << rhs.year <<'\n';
    out << rhs.name << '\n';
    for (auto author : rhs.authors)
    {
    out << author<<'\t';
    }
    return out;
}