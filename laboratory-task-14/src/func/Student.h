#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "Person.h"

class Student : public Person {
private:
	int32_t course;
	int32_t group;
public:
	//Конструкторы
	Student();
	Student(const char*, int32_t, int32_t);
	Student(const Student&);
	//Деструктор
	~Student();

	//Геттеры
	int32_t getCourse() const;
	int32_t getGroup() const;

	//Сеттеры
	void setCourse(int32_t);
	void setGroup(int32_t);

	//Перегрузка ввода и вывода
	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const  Student&);

	//Метод для вывода
	void print(std::ostream&) const override;
};


#endif
