#include "Book.hpp"

//Конструктор с параметрами
Book::Book(int32_t initUDK, AuthorList initAuthors, std::string initName, int32_t initYear)
    : UDK(initUDK), authors(std::move(initAuthors)), name(std::move(initName)), year(initYear) {
}

//Конструктор копирования
Book::Book(const Book &rhs)
    : UDK(rhs.UDK), authors(rhs.authors), name(rhs.name), year(rhs.year) {
}

//Перегрузка оператора присваивания
Book& Book::operator=(const Book &rhs) {
    if (this != &rhs) {
        UDK = rhs.UDK;
        authors = rhs.authors;
        name = rhs.name;
        year = rhs.year;
    }
    return *this;
}

//Геттеры
std::string Book::getName() const
{
    return name;
}

AuthorList Book::getAuthors() const
{
    return authors;
}

void Book::addAuthor(const Author &other) {
    authors.addAuthor(other);
}

//Удалить автора
void Book::deleteAuthor(const Author &other) {
    authors.removeAuthor(other);
}

//Перегрузка оператора ввода
std::istream& operator>>(std::istream& fin, Book& rhs) {
    std::string line;
    std::getline(fin, line, ';');
    if(line.empty()) {
        fin.setstate(std::ios_base::failbit);
        return fin;
    }
    rhs.UDK = std::stoi(line);
    std::getline(fin, line, ';');
    rhs.name = line;
    std::getline(fin, line, ';');
    rhs.year = std::stoi(line);

    rhs.authors = AuthorList();
    std::getline(fin, line, ';');
    std::istringstream iss(line);
    std::string authorStr;
    while (std::getline(iss, authorStr, ',')) {
        std::istringstream authorIss(authorStr);
        Author author;
        authorIss >> author;
        rhs.authors.addAuthor(author);
    }
    return fin;
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Book& rhs) {
    out.clear();
    out << rhs.UDK << ";\n";
    out << rhs.name << ";\n";
    out << rhs.year << ";\n";
    for (size_t i = 0; i < rhs.authors.getAuthorCount(); ++i) {
        out << rhs.authors.getAuthor(i);
        if (i < rhs.authors.getAuthorCount() - 1) {
            out << ',';
        }
    }
    out << "\n**************************************************************\n";
    return out;
}


//Перегрузка операторов сравнения
bool Book::operator==(const Book& other) const
{
    return name == other.name && authors == other.authors;
}

bool Book::operator!=(const Book& other) const 
{
    return !(*this == other);
}
