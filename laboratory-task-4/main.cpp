/*
    В целочисленной квадратной матрице найти:
    − максимальный элемент нижнего правого треугольника матрицы.
    − переставить строки и столбцы матрицы так, чтобы в левом верхнем углу
    матрицы оказался максимальный положительный элемент матрицы.
*/

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 

using std::cout; 
using std::cin; 

void alLocated(int32_t**& matrix, const int32_t& size)
{
    matrix = new int32_t* [size]; 

    for (size_t i = 0; i < size; ++i) { 
        matrix[i] = new int32_t [size]; 
    } 
}

void fillMatrixFromKeyboard(int32_t** matrix, int32_t& size) 
{ 
    cout << "Enter elements of matrix: "; 
    for (size_t i = 0; i < size; ++i) { 
        for (size_t j = 0; j < size; ++j) { 
            cin >> matrix[i][j]; 
        } 
    } 
} 

void fillMatrixFromRandom(int32_t** matrix, const int32_t& size) 
{ 
    int32_t boarder1, boarder2; 
    cout << "Enter boarders: "; 
    cin >> boarder1 >> boarder2; 

    if (boarder2 < boarder1) { 
     std::swap(boarder2, boarder1); 
    } 
    

    for (size_t i = 0; i < size; ++i) { 
        for (size_t j = 0; j < size; ++j) { 
             matrix[i][j] = rand() % (boarder2 - boarder1 + 1) + boarder1 ; 
        } 
    }  
} 

void printMatrix(int32_t** matrix, const int32_t& size) 
{ 
    for (size_t i = 0; i < size; ++i) { 
        for (size_t j = 0; j < size; ++j) { 
            cout << std::setw(4) << matrix[i][j] << " "; 
        } 

    cout << '\n'; 
    } 
} 

int32_t searchOfMaxInRightLowCorner(int32_t** matrix, const int32_t& size) 
{ 
    int32_t max = matrix[0][size-1]; 

    for (size_t i = 0; i < size; ++i) { 
        for(size_t j = size-1; j < size; --j) { 
            if (i > size - 1 - j && matrix[i][j] > max) { 
                max = matrix[i][j]; 
            } 
        } 
    } 
    return max; 
} 

 void findMaxElemInds(int32_t** matrix, const size_t& size, size_t& rowInd, size_t& colInd ) 
{
    int32_t max = matrix[0][0]; 

    for (size_t i = 0; i < size; ++i) { 
        for (size_t j = 0; j < size; ++j) { 
            if (matrix[i][j] > max) { 
                max = matrix[i][j]; 
                rowInd = i; 
                colInd = j; 
            } 
        } 
    } 
}

void movingMaxElementInLeftCorner(int32_t** matrix, const int32_t& size, size_t& rowInd, size_t& colInd) 
{ 
    if (matrix[rowInd][colInd] < 0) { 
        throw "Maximum element is not positive!"; 
    } 
    
    std::swap(matrix[0],matrix[rowInd]);  

        for(size_t i = 0; i < colInd; ++i) {   
                std::swap( matrix[0][i], matrix[0][colInd]); 
            }  
} 

void deleteMemory(int32_t** matrix, const int32_t& size) 
{ 
    for (size_t j = 0; j < size; ++j) { 
        delete[] matrix[j]; 
    } 

    delete[] matrix; 
    cout << "Memory is cleaned"; 
} 

void inputSize(int32_t& n)
{
    while (n <= 0) { 
        cout << " Enter number of rows and columns: "; 
        cin >> n; 
    } 
}


int main() 
{ 
    int32_t** matrix = nullptr; 
    int32_t n = -1; 
    inputSize(n);
    alLocated(matrix, n);

    try { 
        srand(time(NULL)); 
        int32_t op; 
        cout << "Enter 0 - keyboard,1 - random :  "; 
        cin >> op; 

        switch (op) { 
         case 0: 
            fillMatrixFromKeyboard(matrix, n); 
            break; 
         case 1: 
             fillMatrixFromRandom(matrix, n); 
            break; 
         default: 
            std::cout << "Input incorrect value.Get out of my program!"; 
            return 1; 
        } 

        size_t rowInd = 0;
        size_t colInd = 0;
        printMatrix(matrix, n); 
        cout << "\nMaximum element of the lower right triangle of the matrix: " << searchOfMaxInRightLowCorner(matrix, n) << '\n'; 
        findMaxElemInds(matrix, n, rowInd, colInd);
        movingMaxElementInLeftCorner(matrix, n, rowInd, colInd); 
        printMatrix(matrix, n);
        std::cout << "\n"; 
        throw "";  
    } 

     catch (const char* msg) { 
        std::cout << msg; 
        deleteMemory(matrix, n); 
    } 

    return 0; 
}

