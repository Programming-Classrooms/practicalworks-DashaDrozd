#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../func/Book.hpp" 

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
       std::fstream file("src/files/t")
    }


    catch(std::runtime_error e)
    {
        std::cerr << e.what(); 
    }

    return 0;

}