#include "../func/Library.hpp"

#include <gtest/gtest.h>


// Проверка добавления книги в библиотеку
TEST(LibraryTest, AddBook) {
    Library library;
    Book book("Title", {"Author1", "Author2"}, 10.0, 5);
    library.addBook(book);

    ASSERT_EQ(library.findBook(book.getISBN()).getISBN(), book.getISBN());
}

// Проверка поиска книги по ISBN
TEST(LibraryTest, FindBook) {
    Library library;
    Book book("Title", {"Author1", "Author2"}, 10.0, 5);
    library.addBook(book);

    Book& foundBook = library.findBook(book.getISBN());

    ASSERT_EQ(foundBook.getISBN(), book.getISBN());
}

// Проверка удаления книги по ISBN
TEST(LibraryTest, RemoveBook) {
    Library library;
    Book book("Title", {"Author1", "Author2"}, 10.0, 5);
    library.addBook(book);

    ASSERT_TRUE(library.removeBook(book.getISBN()));
    ASSERT_THROW(library.findBook(book.getISBN()), std::runtime_error);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
