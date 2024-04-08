#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Person.h"

class Professor : public Person
{
private:
	char* department;

public:
	//Конструкторы
	Professor();
	Professor(const char*, const char*);
	Professor(const Professor&);
	//Деструктор
	~Professor();

	void setDepartment(char*);//сеттер
	char* getDepartment() const;//геттер

	friend std::istream& operator>>(std::istream&, Professor&);//перегрузка ввода
	friend std::ostream& operator<<(std::ostream&,const Professor&);//перегрузка вывода
	void print(std::ostream&) const override;//метод для вывода
};

#endif //Professor.h
