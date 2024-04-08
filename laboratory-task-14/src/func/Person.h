#ifndef PERSON_CPP
#define PERSON_CPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Person {
protected:
	char* fullName;

public:
    //Конструкторы
	Person();
	Person(const char*);
	Person(const Person&);
	//Деструктор
	~Person();

	void setFullName(char*);//сеттер
	char* getFullName() const;//геттер
	
	//Перегрузка ввода
	friend std::istream& operator>>(std::istream&, Person&);
	//Перегрузка вывода
	friend std::ostream& operator<<(std::ostream&, const Person&);
	//Метод для вывода
	virtual void print(std::ostream&)const;

 };


#endif 