#ifndef STUDENT2SESSION_H
#define STUDENT2SESSION_H
#include "Student1Session.h"
#include <iostream>
#include <cstring>

class Student2Session : public Student1Session{
private:
	int32_t marksSecondSession[5];
	
public:
	Student2Session() = delete;//конструктор по умолчанию
	Student2Session(std::string, int32_t, int32_t, const int32_t, int32_t*, int32_t*);// конструктор с параметрами
	Student2Session(const Student2Session&);// конструктор копирования
	~Student2Session();//деструктор

	//Сеттеры
	void setMarks(int32_t*);
	//Геттеры
	int32_t* getMarks();

	//Оператор вывода
	friend std::ostream& operator<<(std::ostream&, const Student2Session&);
	void print(std::ostream&) const override;

    //Средний балл
    double AverageMark() override;
};

#endif