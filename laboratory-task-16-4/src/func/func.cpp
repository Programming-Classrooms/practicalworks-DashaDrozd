#include "func.hpp"

void fillMatrix(std::vector<std::vector<int>> &matrix, size_t &rows, size_t &columns)
{
    int32_t left, right;
    std::cout << "Enter boundaries for the range of matrix element values: ";
    std::cin >> left >> right;
    if(left > right)
    {
        std::swap(left,right);
    } 

    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < columns; ++j){
           matrix[i][j] = rand() % (right - left + 1) + left;
        }
    }
}

void printMatrix(std::vector<std::vector<int>> &matrix, size_t &rows, size_t &columns)
{

    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < columns; ++j){
           std::cout << std::setw(4) << matrix[i][j] << " ";
        }

        std::cout << '\n';
    }
}

void findMaxElement(std::vector<std::vector<int>> &matrix, size_t &rows, size_t &columns, size_t &rowInd, size_t &columnInd){
    int32_t max = matrix[0][0];
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < columns; ++j){
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
                rowInd = i;
                columnInd =j;
            }
        
        }
    }
}

void deletMaxElementColAndRow(std::vector<std::vector<int>> &matrix, size_t &rows, size_t &rowInd, size_t &columnInd)
{
     matrix.erase(matrix.begin() + rowInd);

    for (auto& rows : matrix) {
        rows.erase(rows.begin() + columnInd);
    }
}

int rowSum(std::vector<int>& row)
{
    int sum = 0;
    for(auto elem:row)
    {
        sum+=elem;
    }

    return sum;
}

void swapRows(std::vector<std::vector<int>>& matrix, size_t& indRow1, size_t& indRow2)
{
    std::vector<int> temp = matrix[indRow1];
    matrix[indRow1] = matrix[indRow2];
    matrix[indRow2] = temp;
}

void sortBySumOfRowsElements(std::vector<std::vector<int>> &matrix)
{
    size_t size = matrix.size(); 
    for(size_t i = 0; i < size - 1; ++i)
    {
       int minSum = rowSum(matrix[i]);
       size_t minInd = i;
       for(size_t j = i + 1; j < size; ++j)
       {
            int currentSum = rowSum(matrix[j]);
            if(currentSum < minSum)
            {
                minSum = currentSum;
                minInd = j;
            }
       }

        if (minInd != i) 
        {
            swapRows(matrix, i, minInd);
        }
    }
}