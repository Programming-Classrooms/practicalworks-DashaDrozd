#include "../func/funct.hpp"
#include <string>
//#include <Windows.h>
#include <sstream>

int main()
{
	// SetConsoleCP('1251');
	// SetConsoleOutputCP('1251');
	try
	{
		std::ifstream file("src/files/Numbers.txt");
		checkFile(file);
		std::string delims;
		getline(file, delims);
		std::string line;
		int32_t counter{ 0 };
		std::string numbs = findNumbs(file, line, delims, counter);
		std::cout << numbs << '\n';
		std::istringstream ss(numbs);
		int32_t* allNumbers = new int32_t[counter];
		for (size_t i = 0; i < counter; ++i)
		{
			ss >> allNumbers[i];
		}
		printArr(allNumbers, counter);
		int32_t* allNumbersCopy = new int32_t[counter];
		sortNumbers(allNumbers, allNumbersCopy, counter);
		printArr(allNumbersCopy, counter);
		file.close();
		std::ifstream fin("src/files/Strings.txt");
		checkFile(fin);
		std::string linesurn;
		std::string delims2;
		getline(fin, delims2);
		int32_t counter2{ 0 };
		std::string* surnames = new std::string[1000];
		findSurnames(fin, linesurn, delims2, counter2, surnames);
		printString(surnames, counter2);
		qsortString(surnames, 0, counter2 - 1);
		printString(surnames, counter2);
		Employee* employee = new Employee[counter2];
		fillChil(employee, surnames, allNumbers, counter2); 
		universalQsort(employee, 0, counter2 - 1, comp);
		outputInTxtFile(employee,counter2);

		}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
