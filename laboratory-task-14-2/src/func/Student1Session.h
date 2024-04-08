#ifndef STUDENT1SESSION_H
#define STUDENT1SESSION_H
#include "Student2.h"
#include <iostream>
#include <cstring>

class Student1Session : public Student2{
protected:
	int32_t marks[4];
	
public:
	Student1Session() = delete;//конструктор по умолчанию
	Student1Session(std::string, int32_t, int32_t, const int32_t, int32_t*);// конструктор с параметрами
	Student1Session(const Student1Session&);// конструктор копирования
	~Student1Session();//деструктор

	//Сеттеры
	void setMarks(int32_t*);
	//Геттеры
	int32_t* getMarks();

	//Оператор вывода
	friend std::ostream& operator<<(std::ostream&, const Student1Session&);
	virtual void print(std::ostream&) const;

	//средний балл 
	virtual double AverageMark();
};

#endif