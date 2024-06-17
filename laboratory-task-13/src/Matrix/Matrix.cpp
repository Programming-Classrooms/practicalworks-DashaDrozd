#include "Matrix.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>


//Заполнение матрицы
void Matrix::fillMatrix()
{
	srand(time(NULL));
	int32_t min, max;
	std::cout << "Enter boarders: ";
	std::cin >> min >> max;

	if (max < min)
	{
		std::swap(max, min);
	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			mtr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

//Конструкторы
Matrix::Matrix(): columns(1), rows(1)
{
	mtr = new int32_t * [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		mtr[i] = new int32_t[columns];
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			mtr[i][j] = 0;
		}
	}
}

Matrix::Matrix(size_t columns, size_t rows):columns(columns), rows(rows)
{
	mtr = new int32_t* [rows];
		for (size_t i = 0; i < rows; ++i)
		{
			mtr[i] = new int32_t[columns];
		}

		//fillMatrix();
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				mtr[i][j] = 0;
			}
		}
}

Matrix::Matrix(const Matrix& rhs): columns(rhs.columns), rows(rhs.rows)
{
	mtr = new int32_t * [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		mtr[i] = new int32_t[columns];
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			mtr[i][j] = rhs.mtr[i][j];
		}
	}
}

//Деструктор
Matrix::~Matrix()
{
	delete[] this->mtr;
}

//Сеттеры и геттеры
size_t Matrix::getColumns() const
{
	return columns;
}

void Matrix::setColumns(int32_t columns)
{
	if (rows <= 0) {
		throw std::invalid_argument("wrong number of columns\n");
	}
}

size_t Matrix::getRows() const
{
	return rows;
}

void Matrix::setRows(int32_t rows)
{
	if (rows <= 0) {
		throw std::invalid_argument("wrong number of rows\n");
	}
}

//Скобки
int32_t*& Matrix::operator[](int32_t index)
{
	if (index < 0 || index >= rows) {
		throw std::out_of_range("bad index\n");
	}
	return mtr[index];
}
 
 //Присваивание
Matrix& Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			delete[] mtr[j];
		}
		delete[] mtr;

		columns = rhs.columns;
		rows = rhs.rows;

		mtr = new int32_t * [rows];
		for (size_t i = 0; i < rows; ++i)
		{
			mtr[i] = new int32_t[columns];
		}

		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				mtr[i][j] = rhs.mtr[i][j];
			}
		}
	}

	return *this;
}

//Сумма
Matrix Matrix::operator+(const Matrix& rhs) const
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Size of matrices mismatch");
	}
	Matrix res(rhs.columns,rhs.rows);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			res.mtr[i][j] = mtr[i][j] + rhs.mtr[i][j];
		}
	}
	return res;
}

//Умножение на скаляр справа
Matrix Matrix::operator*(int32_t k) const
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			mtr[i][j] *= k;
		}
	}
	return *this;
}

//Деление
Matrix Matrix::operator/(int32_t k)
{
	if (k == 0) {
		throw std::invalid_argument("Division by zero!");
	}
	
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < columns; ++j)
			{
				static_cast<double>(mtr[i][j] /= k);
			}
		}
		return *this;
}

//Сравнение
bool Matrix::operator==(const Matrix& rhs)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (mtr[i][j] != rhs.mtr[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& rhs) 
{
	return !(*this == rhs);
}

//Разность
Matrix Matrix::operator-(const Matrix& rhs) const
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Size of matrices mismatch");
	}
	Matrix res(rhs.columns, rhs.rows);
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			res.mtr[i][j] = mtr[i][j] - rhs.mtr[i][j];
		}
	}
	return res;
}

//Перемножение матриц
Matrix Matrix::operator*(const Matrix& rhs) const
{
	if (columns != rhs.rows) {
		throw std::invalid_argument("Matrices are inconsiztent");
	}
	Matrix res(rhs.columns, rows);
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < rhs.columns; ++j)
			{
				for (size_t k = 0; k < columns; ++k)
				{
					res.mtr[i][j] += mtr[i][k] * rhs.mtr[k][j];
				}
			}
		}
	return res;
}

//Умножение на скаляр слева
Matrix operator*(int32_t k, const Matrix& rhs)
{
	return rhs * k;
}


//Ввод
std::istream& operator>>(std::istream& in, Matrix& rhs)
{
	std::cout << "Enter number of rows and columns: ";
	in >> rhs.columns >> rhs.rows;
	if (rhs.columns <= 0 || rhs.rows <= 0)
	{
		std::cout << "Row and columns must be natural number: ";
	}

	rhs.mtr = new int32_t * [rhs.rows];
	for (size_t i = 0; i < rhs.rows; ++i)
	{
		rhs[i] = new int32_t[rhs.columns];
	}

	int32_t op;
	std::cout << "Enter 0 - keyboard,1 - random :  ";
	in >> op;
	switch (op)
	{
	case 0:
		for (size_t i = 0; i < rhs.rows; ++i)
		{
			for (size_t j = 0; j < rhs.columns; ++j)
			{
				in >> rhs.mtr[i][j];
			}
		}
		break;
	case 1:
		rhs.fillMatrix();
		break;
	default:
		std::cout << "Input incorrect value.Get out of my program!";
	}
	return in;
}

//Вывод
std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
	for (size_t i = 0; i < rhs.rows; ++i)
	{
		for (size_t j = 0; j < rhs.columns; ++j)
		{
			out << std::setw(4) <<rhs.mtr[i][j] << " ";
		}

		out << '\n';
	}
	return out;
}
