/*
	3. Строка состоит из слов. Найти все слова-палиндромы и занести их в
           новую строку в порядке возрастания их длин. Слова в новой строке должны
           разделяться ровно одним пробелом.
*/


#include <iostream>
#include <string>
#include <exception>


void isEmptyString (const std::string& str)
{
	if (str.empty() == true) {
		throw std::exception ("String is empty!\n");
        }

}


bool isPrime(int64_t num)
{
	if (num < 2) {
		return false;
	}
	
	uint32_t numRoot = sqrt(num) + 1;
	
	for (size_t i = 2; i < numRoot; ++i) {
	
		if (num % i == 0 && i != num) {
			return false;
		}
	}
	
	return true;
}

bool isNumber(std::string word)
{
	size_t wordLen = word.length();
	for (size_t i = 0; i < wordLen; ++i) {
		if (!isdigit(word[i])) {
			return false;
		}
	}
	return true;
}

std::string findPrimeNumb(std::string line, std::string delims, std::string newLine)
{
    std::string word;
    std::string::size_type begInd;
    begInd = line.find_first_not_of(delims);
    while (begInd != std::string::npos) {
        std::string::size_type endInd;
        endInd = line.find_first_of(delims, begInd);

        if (endInd == std::string::npos) {
            endInd = line.length();
        }
        
        word = line.substr(begInd, endInd - begInd);
        int64_t num = 0;

		if (isNumber(word)) {
			num = std::stoi(word);
		}
		
            if (isPrime(num)) {
				newLine = newLine + std::to_string(num) + ' ';
        }
        
        begInd = line.find_first_not_of(delims, endInd);
    
    }

	if (newLine.empty() == true) {
		throw std::exception("Prime numbers are not exist\n");
	}

	return newLine;
}

int main()
{
	try {
		std::string line, newLine;
		std::string delims = ".,?!";
		std::cout << "Input string: ";
		std::getline(std::cin, line);
		isEmptyString(line);
		std::cout << "the result:" << findPrimeNumb(line, delims, newLine);
	}

	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}
	return 0;

}

