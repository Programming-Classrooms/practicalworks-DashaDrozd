#include "../MyString/MyString.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

int main()
{
	MyString str1("Hello,");
	MyString test("world!");
	MyString str3;
	MyString test2("world!");
	MyString vvod;
	std::cin >> vvod;
	std::cout << vvod << std::endl;

	str3 = str1 + test;
	std::cout << str3 << std::endl;

	if (test2 == test)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (test2 < str3)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	return 0;
}
