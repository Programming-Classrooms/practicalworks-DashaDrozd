#ifndef FRACTION
#define FRACTION
#include <iostream>


class Fraction {
private:
	int32_t n;//числитель
	int32_t d;//знаменатель
    
public:
	//Конструкторы
	Fraction();
	Fraction(int32_t n, int32_t d);
	Fraction(const Fraction&);
	//Деструктор
	~Fraction();

	//Нод
	int32_t gcd(int32_t, int32_t);

	//Сеттеры
	void SetN(int32_t n);
	void SetD(int32_t d);

	//Геттеры
	int32_t GetN();
	int32_t GetD();

	//Присваивание
	Fraction& operator=(const Fraction&);

	//Сокращение
	Fraction& simplify();

	//Арифметические операторы
	Fraction operator-();
	Fraction operator+(const Fraction&);
	Fraction operator+(int32_t k);
	Fraction operator+=(const Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	
	//Сравнение
	bool operator==(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator>(const Fraction&) const;

	//Инкременты и Декременты
	Fraction operator++(int32_t k);
	Fraction& operator++();
	Fraction operator--(int32_t k);
	Fraction& operator--();

	//Обратная дробь
	Fraction operator~() const;

	//Приведение к дабл
	Fraction cast();

	//Ввод вывод
	friend std::ostream& operator<<(std::ostream& out, const Fraction& rhs);
	friend std::istream& operator>>(std::istream& in, Fraction& c);

};
#endif
