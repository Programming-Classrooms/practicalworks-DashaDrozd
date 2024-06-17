#include <utility>
#include <vector>

#include "Library.hpp"

//Конструктор с параметрами
Library::Library(std::vector<Book> initBooks):books(initBooks)
{
}

//Перегрузка оператора присваивания
Library &Library::operator=(const Library &rhs)
{
    if(this!= &rhs)
    {
        books = rhs.books;
    }

    return *this;
}

//Добавление книги
void Library::addBook(const Book &rhs)
{
    books.push_back(rhs);
}

//Удаление книги
void Library::deleteBook(const Book &rhs)
{
    books.erase((std::remove(books.begin(), books.end(), rhs)), books.end());
}

// Поиск книги по названию
void Library::searchByName(std::string title)
{
    int32_t counter = 0;

   for(Book& book:books)
   {
     if(book.getName() == title)
     {
        ++counter;
        std::cout << book << " ";
     }
   }

   if(counter == 0)
   {
        throw std::runtime_error("There are not such books\n");
   }
}

//Поиск книги по автору
void Library::searchByAuthor(Author auth)
{
    std::vector<int32_t> a;
    std::vector<int32_t> b;
    int32_t counter = 0;
   for (const Book& book : books) {
        AuthorList authors = book.getAuthors();
        const std::vector<Author>& authorsList = authors.getAuthors();
        if ((std::find(authorsList.begin(), authorsList.end(), auth)) != authorsList.end()) {
            ++counter;
            std::cout << book << std::endl;
        }
    }

     if(counter == 0)
   {
        throw std::runtime_error("There are not such books\n") ;
   }
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Library& library) {
    for (const auto& book : library.books) {
        out << book << " ";
        out << std::endl;
    }

    out << std::endl;
    return out;
}

//Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, Library& library) {
    Book book;
    while (in >> book) {
        library.addBook(book);
    }
    return in;
}
