#include "Student.h"

//Конструкторы
Student::Student():Person(),course(1),group(1)
{
}

Student::Student(const char* name, int32_t courses , int32_t groups):Person(name), course(courses), group(groups)
{
}

Student::Student(const Student& rhs)
{
	course = rhs.course;
	group = rhs.group;
}

//Деструктор
Student::~Student() 
{}

//Геттеры
int32_t Student::getCourse() const
{
	return this -> course;
}

int32_t Student::getGroup() const
{
	return this->group;
}

//Сеттеры
void Student::setCourse(int32_t initCourse)
{
	this->course = initCourse;
}

void Student::setGroup(int32_t initGroup)
{
	this->group = initGroup;
}

//Метод для вывода
void Student::print(std::ostream& out) const
{
	out << *this << '\n';
}

//Перегрузка ввода
std::istream& operator>>(std::istream& in, Student& rhs)
{
	in >> *((Person*)&rhs);
	std::cout << "\nEnter course of student: ";
	in >> rhs.course;
	std::cout << "\nEnter group of student: ";
	in >> rhs.group;

	return in;
}

//Перегрузка вывода
std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
	out << static_cast<Person>(rhs);
	out << "\nStudent's course: " << rhs.course << "\n Student's group: " << rhs.group;

	return out;
}
