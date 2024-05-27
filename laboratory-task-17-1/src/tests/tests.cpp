#include <gtest/gtest.h>

#include "../func/Library.hpp"
#include "../func/Book.hpp"
#include "../func/AuthorList.hpp"
#include "../func/Author.hpp"

// Тест для добавления книги
TEST(LibraryTest, AddBook) {
    Library lib;

    // Создание авторов и списков авторов
    Author auth1("LastName1", "FirstName1", "MiddleName1");
    AuthorList authList1;
    authList1.addAuthor(auth1);

    Author auth2("LastName2", "FirstName2", "MiddleName2");
    AuthorList authList2;
    authList2.addAuthor(auth2);

    // Создание книг
    Book book1(1, authList1, "Title1", 2020);
    Book book2(2, authList2, "Title2", 2021);

    // Добавление книг в библиотеку
    lib.addBook(book1);
    lib.addBook(book2);

    // Проверка содержимого библиотеки
    std::ostringstream oss;
    oss << lib;
    std::string output = oss.str();

    EXPECT_NE(output.find("Title1"), std::string::npos);
    EXPECT_NE(output.find("Title2"), std::string::npos);
}


// Тест для удаления книги
TEST(LibraryTest, DeleteBook) {
    Library lib;

    Author auth1("LastName1", "FirstName1", "MiddleName1");
    AuthorList authList1;
    authList1.addAuthor(auth1);

    Author auth2("LastName2", "FirstName2", "MiddleName2");
    AuthorList authList2;
    authList2.addAuthor(auth2);

    Book book1(1, authList1, "Title1", 2020);
    Book book2(2, authList2, "Title2", 2021);

    lib.addBook(book1);
    lib.addBook(book2);
    lib.deleteBook(book1);

    std::ostringstream oss;
    oss << lib;
    std::string output = oss.str();

    EXPECT_EQ(output.find("Title1"), std::string::npos);
    EXPECT_NE(output.find("Title2"), std::string::npos);
}

// Тест для поиска книги по названию
TEST(LibraryTest, SearchByName) {
    Library lib;

    Author auth1("LastName1", "FirstName1", "MiddleName1");
    AuthorList authList1;
    authList1.addAuthor(auth1);

    Author auth2("LastName2", "FirstName2", "MiddleName2");
    AuthorList authList2;
    authList2.addAuthor(auth2);

    Book book1(1, authList1, "Title1", 2020);
    Book book2(2, authList2, "Title2", 2021);

    lib.addBook(book1);
    lib.addBook(book2);

    std::ostringstream oss;
    EXPECT_NO_THROW(lib.searchByName("Title1"));
}

// Тест для поиска книги по автору
TEST(LibraryTest, SearchByAuthor) {
    Library lib;

    Author auth1("LastName1", "FirstName1", "MiddleName1");
    AuthorList authList1;
    authList1.addAuthor(auth1);

    Author auth2("LastName2", "FirstName2", "MiddleName2");
    AuthorList authList2;
    authList2.addAuthor(auth2);

    Book book1(1, authList1, "Title1", 2020);
    Book book2(2, authList2, "Title2", 2021);

    lib.addBook(book1);
    lib.addBook(book2);

    std::ostringstream oss;
    EXPECT_NO_THROW(lib.searchByAuthor(auth1));
}

// Тест для проверки оператора вывода
TEST(LibraryTest, OutputOperator) {
    Library lib;

    Author auth1("LastName1", "FirstName1", "MiddleName1");
    AuthorList authList1;
    authList1.addAuthor(auth1);

    Author auth2("LastName2", "FirstName2", "MiddleName2");
    AuthorList authList2;
    authList2.addAuthor(auth2);

    Book book1(1, authList1, "Title1", 2020);
    Book book2(2, authList2, "Title2", 2021);

    lib.addBook(book1);
    lib.addBook(book2);

    std::ostringstream oss;
    oss << lib;
    std::string output = oss.str();

    EXPECT_NE(output.find("Title1"), std::string::npos);
    EXPECT_NE(output.find("Title2"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
