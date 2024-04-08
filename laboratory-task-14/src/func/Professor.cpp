#include "Professor.h"

//Конструкторы
Professor::Professor():Person(), department(nullptr)
{
}

Professor::Professor(const char* name, const char* depart): Person(name)
{
	department = new char[strlen(depart) + 1];
	strcpy(department, depart);
}

Professor::Professor(const Professor& rhs)
{
	department = new char[strlen(rhs.department) + 1];
	strcpy(department, rhs.department);
}

//Деструктор
Professor::~Professor()
{
	delete[] department;
}

//Сеттер
void Professor::setDepartment(char* rhs)
{
	 delete[] department;
    department = new char[strlen(rhs) + 1];
    strcpy(department, rhs);
}

//Геттер
char* Professor::getDepartment() const
{
	return this->department;
}

//Метод для печати
void Professor::print(std::ostream& out) const
{
	out << *this << '\n';
}

//Оператор ввода
std::istream& operator>>(std::istream& in, Professor& rhs)
{
	in >> *((Person*)&rhs);
	std::cout << "\nEnter department: ";
	char buffer[1000];
	in >> buffer;
	rhs.setDepartment(buffer);
	return in;
}

//Оператор вывода
std::ostream& operator<<(std::ostream& out,const Professor& rhs)
{
	out << static_cast<Person>(rhs) << "\nDepartment: " << rhs.department;
	return out;
}
