/*
	В текстовом файле input.txt в первой строке записано одно слово, в  остальных строках 
	- текст,слова в котором разделены одним или  несколькими пробелами. Перед первым, а также после
	 последнего слова  строки пробелы могут отсутствовать. Подсчитать, сколько раз это слово 
	встречается в тексте.  														 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Header.hpp"


int main()
{
	try {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::string line,compWord; 
		std::fstream file("input.txt");
		checkFile(file);
		std::string delims = " ";
		int32_t count = 0;
		compWord = getWord(file, compWord);
		transform(file, delims, line, compWord, count);
		std::cout << count;
	}
	
	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}
	return 0;

}
