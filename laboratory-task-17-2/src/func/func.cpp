#include "../func/func.hpp"

void checkFile(std::ifstream &file)
{
    if(!file.good())
    {
        throw std::runtime_error("File is not exsist!\n");
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

void toLower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](char ch){return tolower(ch);});
}

std::vector<std::string> splitIntoWords(std::string line)
{
	std::string word;
    std::vector <std::string> words;
    std::string delims =" ;:/,.-_";
	std::string::size_type begInd;
	begInd = line.find_first_not_of(delims);
	while (begInd != std::string::npos)
	{
		std::string::size_type endInd;
		endInd = line.find_first_of(delims, begInd);
		if (endInd == std::string::npos)
		{
			endInd = line.length();
		}
		word = line.substr(begInd, endInd - begInd);
        words.push_back(word);
		begInd = line.find_first_not_of(delims, endInd);

	}
	
    return words;
}
