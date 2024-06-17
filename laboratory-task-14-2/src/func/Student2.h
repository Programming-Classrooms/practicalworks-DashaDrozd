#ifndef STUDENT2_H
#define STUDENT2_H
#include <iostream>
#include <cstring>

class Student2 {
protected:
	const size_t studentID;
	std::string name;
	int32_t course;
	int32_t group;
	const int32_t recordNumber;
	static size_t counter;
	Student2();//конструктор по умолчанию
public:
	Student2(std::string, int32_t, int32_t, const int32_t);// конструктор с параметрами
	Student2(const Student2&);// конструктор копирования
	~Student2();//деструктор

	//Сеттеры
	void setName(std::string);
	void setCourse(int32_t);
	void setGroup(int32_t);

	//Геттеры
	std::string getName();
	int32_t getCourse();
	int32_t getGroup();
	const int32_t getRecordNumber();

	//Оператор вывода
	friend std::ostream& operator<<(std::ostream&, const Student2&);
	virtual void print(std::ostream&) const;

};

#endif