#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <stdexcept>

class Matrix {
private:
	size_t columns;
	size_t rows;
	int32_t** mtr;
	void fillMatrix();
public:
	//Конструкторы
	Matrix();
	Matrix(size_t, size_t);
	Matrix(const Matrix&);
	//Деструктор
	~Matrix();

	//Сеттеры и геттеры
	size_t getColumns() const;
	void setColumns(int32_t columns);
	size_t getRows() const;
	void setRows(int32_t rows);

	//Перегрузка скобок
	int32_t*& operator[](int32_t index);
	//Присваивание
	Matrix& operator=(const Matrix&);
	
	//Арифметические операции
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;

	//Умножение на скаляр справа
	Matrix operator*(int32_t) const;
	friend Matrix operator*(int32_t,const Matrix&);//слева
	Matrix operator/(int32_t);//деление

	//Сравнение
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);

	//Ввод и вывод
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif 