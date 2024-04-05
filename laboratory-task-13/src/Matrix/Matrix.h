#ifndef MATRIX_CPP
#define MATRIX_CPP
#include <iostream>
#include <stdexcept>

class Matrix {
private:
	size_t columns;
	size_t rows;
	int32_t** mtr;
	void fillMatrix();
public:
	Matrix();
	Matrix(size_t, size_t);
	Matrix(const Matrix&);
	~Matrix();

	size_t getColumns() const;
	void setColumns(int32_t columns);
	size_t getRows() const;
	void setRows(int32_t rows);

	int32_t*& operator[](int32_t index);
	Matrix& operator=(const Matrix&);

	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;

	Matrix operator*(int32_t) const;
	friend Matrix operator*(int32_t,const Matrix&);
	Matrix operator/(int32_t);

	
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);

	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif 