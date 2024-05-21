/*Объявить целочисленную матрицу типа vector<vector<int>>, размер
матрицы и границы интервалов для элементов, содержащихся в матрице,
ввести с клавиатуры. Выполнить следующие действия с матрицей:
- заполнить случайными значениями;
- удалить строку и столбец, на пересечении которых стоит максимальный
элемент матрицы (первый из найденных);
- упорядочить строки матрицы по возрастанию сумм элементов строк (без
использования алгоритма sort).
Написать все необходимые тесты и выполнить обработку исключений*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "../func/func.hpp"

int main()
{
	try
	{
	size_t rows;
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	size_t columns;
	std::cout << "\nEnter number of columns: ";
	std::cin >> columns;
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));
	fillMatrix(matrix,rows,columns);
	printMatrix(matrix,rows, columns);
	size_t rowInd = 0;
	size_t columnInd = 0;
	findMaxElement(matrix, rows, columns, rowInd, columnInd);
	deletMaxElementColAndRow(matrix, rows, rowInd, columnInd);
	std::cout << "\nMatrix without max element row and column: \n";
	--rows;
	--columns;
	printMatrix(matrix, rows, columns);
	sortBySumOfRowsElements(matrix);
	std::cout << "\nSort of matrix by sum of rows elements: \n";
	printMatrix(matrix, rows, columns);
	}

	catch (const std::out_of_range& e)
	{
        std::cerr << e.what() << '\n';
    }
	catch (const std::runtime_error& e)
	{
        std::cerr << e.what() << '\n';
    }
	
	return 0;
}