#include "Student2.h"

size_t Student2::counter = 0;

//Конструкторы
Student2::Student2():studentID(++counter), name("Strashnov"), course(1), group(1),recordNumber(1)//с по умолчанию
{
}

Student2::Student2(std::string initName, int32_t initCourse, int32_t initGroup, const int32_t initRecordNumber):studentID(++counter), name(initName), course(initCourse), group(initGroup), recordNumber(initRecordNumber) //с параметрами
{
}

Student2::Student2(const Student2& rhs):studentID(++counter),recordNumber(rhs.recordNumber)//Копирования
{
	name = rhs.name;
	course = rhs.course;
	group = rhs.group;
}

//Деструктор
Student2::~Student2()
{
}

//Сеттеры
void Student2::setName(std::string initName)
{
	this->name = initName;
}

void Student2::setCourse(int32_t initCourse)
{
	this->course = initCourse;
}

void Student2::setGroup(int32_t initGroup)
{
	this->group = initGroup;
}

//Геттеры
std::string Student2::getName()
{
	return this->name;
}

int32_t Student2::getCourse()
{
	return this->course;
}

int32_t Student2::getGroup()
{
	return this->group;
}

const int32_t Student2::getRecordNumber()
{
	return this->recordNumber;
}

void Student2::print(std::ostream& out) const
{
	out << *this;
}

//Оператор ввода
std::ostream& operator<<(std::ostream& out, const Student2& rhs)
{
	out << rhs.studentID << ". Student's name:  " << rhs.name << "\nStudent's course: " << rhs.course << "\nStudent's group: " << rhs.group << "\nStudent's record number: " << rhs.recordNumber << '\n';
	return out;
}
