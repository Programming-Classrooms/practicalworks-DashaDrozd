#include "func.hpp"

void checkFile(std::ifstream& file)
    {
        if (!file.good()) {
            throw std::runtime_error("File is not exist!");
        }
        if (!file) {
            throw std::runtime_error("File is not open!");
        }
        if (file.peek() == EOF) {
            throw std::runtime_error("File is empty!");
        }
    }

bool comp(std::string &word1, std::string &word2)
{ 
	std::string aLow = word1;
    std::string bLow = word2;
    std::transform(aLow.begin(), aLow.end(), aLow.begin(), ::tolower);
    std::transform(bLow.begin(), bLow.end(), bLow.begin(), ::tolower);
    return aLow < bLow;
}

void print(std::vector<std::string>& str)
{
	std::cout <<'\n';
	for (auto& word : str) {
		std::cout << word << ' ';
	}
}

void printByFirstLetter(std::vector<std::string>& str)
{
	char letter;
	std::cout << "\nВведите первую букву слов которые хотите напeчатать: ";
	std::cin >> letter;
	size_t counter = 0;
	std::cout << "\nСлова, начинающиеся на " << letter << " : ";
	for(const auto& word : str)
	{
		if(word[0] == letter){
			std::cout << word <<' ';
			++counter;
		}
		
	}

	if(counter == 0 )
	{
		throw std::out_of_range("В данном контейнере нет слов на заданную букву!\n");
	}
}

void deleteByFirstLetter(std::vector<std::string>& str)
{
	char letter;
	std::cout << "\nВведите первую букву слов которые хотите удалить: ";
	std::cin >> letter;
	size_t counter = 0;
	
	for(size_t i = 0; i < str.size(); ++i)
	{
		std:: string word = str[i];
		if(word[0] == letter){
			str.erase(str.begin() + i);
			i--;
		}
	}
}