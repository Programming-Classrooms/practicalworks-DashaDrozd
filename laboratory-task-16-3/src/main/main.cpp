#include "../func/func.hpp"

int main(){
	try{
  	setlocale(LC_ALL, ".1251");
	std::vector <std::string> strings;
	std::ifstream file("src/files/text.txt");
	checkFile(file);
	std::string word;
	std::string line;
	std::getline(file, line);
	std::istringstream ss(line);
	
	while (ss) {
		ss >> word;
		strings.push_back(word);
	}
	strings.pop_back();
	print (strings);
	std::sort(strings.begin(), strings.end());
	print (strings);
	printByFirstLetter(strings);
	deleteByFirstLetter(strings);
	print(strings);
	}

	catch(std::invalid_argument e)
	{
		std::cout << e.what() <<'\n';
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what() <<'\n';
	}

	catch(std::runtime_error e)
	{
		std::cout << e.what() <<'\n';
	}
	return 0;
}
