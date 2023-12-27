#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>

void checkFile(std::fstream& file);
std::string getWord(std::fstream& fin, std::string& compWord);
int32_t countOfWordRepeats(std::string line, std::string delims, std::string& word, int32_t& count);
void transform(std::fstream& file, std::string delims, std::string line, std::string& word, int32_t& count);

#endif 
