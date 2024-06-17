#include <algorithm>

#include "AuthorList.hpp"

//Конструктор
AuthorList::AuthorList(std::vector<Author> list): authors(list)  
{
}

// Добавление автора в список
void AuthorList::addAuthor(const Author& author) {
    authors.push_back(author);
}

// Удаление автора из списка
void AuthorList::removeAuthor(const Author& author) {
    authors.erase(std::remove(authors.begin(), authors.end(), author), authors.end());
}

// Поиск автора по фамилии
Author& AuthorList::findAuthorByLastName(const std::string& lastName) {
    for (auto& author : authors) {
        if (author.getLastName() == lastName){
            return author;
        }
    }
}

// Получение количества авторов в списке
size_t AuthorList::getAuthorCount() const {
    return authors.size();
}

// получение автора по индексу
const Author& AuthorList::getAuthor(size_t index) const{
    return authors.at(index);
}

const std::vector<Author>& AuthorList::getAuthors() const {
    return authors;
}


//Перегрузка оператора сравнения
bool AuthorList::operator==(const AuthorList &other) const
{
    return authors == other.authors;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const AuthorList& authorList) {
    for (const auto& author : authorList.authors) {
        os << author << " ";
    }
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, AuthorList& authorList) {
    Author author;
    while (is >> author) {
        authorList.addAuthor(author);
    }
    return is;
}
