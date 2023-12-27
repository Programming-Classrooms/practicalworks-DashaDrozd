#include <iostream>
#include <fstream>
#include <string>
#include "Header.hpp"


void checkFile(std::fstream& file)
{
	if (!file.good()) {
		throw std::exception("File is not exist!");
	}
	if (!file) {
		throw std::exception("File is not open!");
	}
	if (file.peek() == EOF) {
		throw std::exception("File is empty!");
	}
}

std::string getWord(std::fstream& fin, std::string& word)
{
	getline(fin, word);
	return word;
}

int32_t countOfWordRepeats(std::string line, std::string delims,std::string& compWord, int32_t& count)
{
	std::string words;
	std::string::size_type begInd;
	begInd = line.find_first_not_of(delims);
	
	while (begInd != std::string::npos) {
		std::string::size_type endInd;
		endInd = line.find_first_of(delims, begInd);
		
		if (endInd == std::string::npos) {
			endInd = line.length();
		}
		words = line.substr(begInd, endInd - begInd);
		int32_t res = compWord.compare(words);
		
		if (res == 0) {
			count++;
		}
		begInd = line.find_first_not_of(delims, endInd);

	}
	
	if (count == 0) {
		throw std::exception("Word is not repeat!");
	}
		
	return 0;
}
void transform(std::fstream& file, std::string delims, std::string line, std::string& compWord, int32_t& count)
{

	while (getline(file, line)) {
		countOfWordRepeats(line, delims, compWord, count);

	}
}


