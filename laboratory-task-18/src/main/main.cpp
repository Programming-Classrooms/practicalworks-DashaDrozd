#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

#include "../func/Library.hpp" 


int main ()
{
    Library libr;
    Book aBook;
    Book bBook;
    std::cin >> bBook;
    Book cBook("Groza", {"Ostrovsky Alexandr"}, 12.66, 35);
    Book dBook("1984", {"Arc trt","Gorg Oruell"}, 21.33, 19); 


    libr.addBook(aBook);
    libr.addBook(bBook);
    libr.addBook(cBook);
    libr.addBook(dBook);

    std::cout << "List of books: \n";
    libr.viewBooks();
    std::cout << "\n**********************************\n";
    std::cout << libr.findBook("2"); 
    libr.removeBook("3");

    std::cout << "\n**********************************\n";
    aBook.addAuthor("Tutchev");
    libr.addAuthor("1", "Pushkin");
    libr.removeAuthor("4", "Arc trt");
    libr.sortBooksByTitle();

    return 0;
}
