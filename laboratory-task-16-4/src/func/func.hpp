#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>


void fillMatrix(std::vector<std::vector<int>>&, size_t&, size_t&);
void printMatrix(std::vector<std::vector<int>>&, size_t&, size_t&);
void findMaxElement(std::vector<std::vector<int>>&, size_t&, size_t&, size_t&, size_t&);
void deletMaxElementColAndRow(std::vector<std::vector<int>>&, size_t&, size_t&, size_t&);
int rowSum(std::vector<int>&);
void swapRows(std::vector<std::vector<int>>&, size_t&, size_t&);
void sortBySumOfRowsElements(std::vector<std::vector<int>>&);


#endif