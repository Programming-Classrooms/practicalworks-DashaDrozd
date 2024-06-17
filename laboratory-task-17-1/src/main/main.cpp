#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>

#include "../func/Library.hpp" 

void checkFile(std::fstream& file)
{
    if(!file.good())
    {
        throw std::runtime_error("File is not exist!\n");
    }

     if(!file)
    {
        throw std::runtime_error("File is not opened!\n");
    }
     if(file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!\n");
    }
}

int main ()
{
    try{
       std::fstream file("src/files/books.txt");
       checkFile(file);
       Library lib;
       file >> lib;
       std::cout << lib;
       Author c("Островский", "Александр", "Николаевич");
       AuthorList auth({c});
       Book b(123457, auth, "Гроза", 1957);
       lib.addBook(b);
       std::cout << lib <<"\n ----------------------------------------------------------------------\n";
       lib.deleteBook(b);
       std::cout << lib <<"\n --------------------------------------------------------------------\n";
       Author a("Булгаков", "Михаил", "Афанасьевич");
       lib.searchByAuthor(a);
       std::cout<<"\n ----------------------------------------------------------------------------\n";
       lib.searchByName(" Мастер и Маргарита");
       std::cout << "\n ---------------------------------------------------------------------------\n";
    }


    catch(std::runtime_error e)
    {
        std::cerr << e.what(); 
    }
    catch(std::invalid_argument err)
    {
        std::cerr << err.what();
    }

    return 0;

}
