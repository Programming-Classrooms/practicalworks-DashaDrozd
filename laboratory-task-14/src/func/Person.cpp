#include "Person.h"

//Констурукторы
Person::Person()
{
	fullName = new char[1000];
	fullName[0] = '\0';
}

Person::Person (const char* name)
{
	fullName = new char[strlen(name) + 1];
	strcpy(fullName, name);
}

Person::Person(const Person& rhs)
{
	fullName = new char[strlen(rhs.fullName) + 1];
	strcpy(fullName, rhs.fullName);
}

//Деструктор
Person::~Person()
{
	/*if (fullName != nullptr)
	{
		delete [] fullName;
		fullName = nullptr;
	}*/
	delete[] fullName;
}		

//Сеттер
void Person::setFullName(char* rhsName)
{
	if (this->fullName != nullptr) {
		delete[] fullName;
	}
	this->fullName = new char[strlen(rhsName) + 1];
	strcpy(this->fullName, rhsName);
}


//Геттер
char* Person::getFullName() const
{
	return this -> fullName;
}

//Метод для вывода
void Person::print(std::ostream& out) const
{
	out << *this  << '\n';
}

//Перегрузка ввода
std::istream& operator>>(std::istream& in, Person& rhs)
{
	std::cout << "Enter full name: ";
	char buffer[1000];
	in.getline(buffer,2000);
	rhs.fullName = new char[strlen(buffer) + 1];
	strcpy(rhs.fullName, buffer);
	return in;
}

//Перегрузка вывода
std::ostream& operator<<(std::ostream& out, const Person& rhs)
{
	out << "Full name:" << rhs.fullName;

	return out;
}
