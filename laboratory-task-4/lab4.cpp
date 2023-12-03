#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
 
using std::cout; 
using std::cin; 
 
void fillMatrixFromKeyboard(int32_t** matrix, int32_t& size) 
{ 
 cout << "Enter elements of matrix: "; 
 for (size_t i = 0; i < size; ++i)  
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   cin >> matrix[i][j]; 
  } 
 } 
} 
 
void fillMatrixFromRandom(int32_t** matrix, const int32_t& size) 
{ 
 int32_t min, max; 
 cout << "Enter boarders: "; 
 cin >> min >> max; 
 
 if (max < min) 
 { 
  std::swap(max, min); 
 } 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   matrix[i][j] = rand() % (max - min + 1) + min ; 
  } 
 }  
} 
 
void printMatrix(int32_t** matrix, const int32_t& size) 
{ 
 for (size_t i = 0; i < size; ++i) 
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   cout << std::setw(4) << matrix[i][j] << " "; 
  } 
  cout << '\n'; 
 } 
} 
 
int32_t searchOfMaxInRightLowCorner(int32_t** matrix, const int32_t& size) 
{ 
 int32_t max = matrix[0][size-1]; 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  for(size_t j = size-1; j < size; --j) 
  { 
   if (i > size - 1 - j && matrix[i][j] > max) 
   { 
    max = matrix[i][j]; 
   } 
  } 
 } 
 return max; 
} 
 
 void findMaxElemInds(int32_t** matrix, const size_t& size, size_t& rowInd, size_t& colInd ) 
{
 int32_t max = matrix[0][0]; 
 for (size_t i = 0; i < size; ++i) 
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   if (matrix[size-1-i][size-1-j] > max) 
   { 
    max = matrix[size-1-i][size-1-j]; 
    rowInd = size-1-i; 
    colInd = size-1-j; 
   } 
  } 
 } 
}

void movingMaxElementInLeftCorner(int32_t** matrix, const int32_t& size, size_t& rowInd, size_t& colInd) 
{ 
 if (matrix[rowInd][colInd] < 0)  
 { 
  throw "Maximum element is not positive!"; 
 } 
   std::swap(*matrix[0],*matrix[rowInd]);  
    for(size_t i = 0; i < size; ++i)
    {

      for (size_t j = 0; j < colInd; ++j) 
         {    
   
             std::swap( matrix[i][j], matrix[i][colInd]); 
         } 
    }
 printMatrix(matrix, size); 
} 

void deleteMemory(int32_t** matrix, const int32_t& size) 
{ 
 for (size_t j = 0; j < size; ++j) 
 { 
  delete[] matrix[j]; 
 } 
 delete[] matrix; 
 cout << "Memory is cleaned"; 
} 
 
 
 
int main() 
{ 
 int32_t** matrix; 
 int32_t n = -1; 

 while (n <= 0) 
 { 
  cout << " Enter number of rows and columns: "; 
  cin >> n; 
 } 

 matrix= new int32_t * [n]; 

 for (size_t i = 0; i < n; ++i) 
 { 
  matrix[i] = new int32_t [n]; 
 } 

 try 
 { 
  srand(time(NULL)); 
  int32_t op; 
  cout << "Enter 0 - keyboard,1 - random :  "; 
  cin >> op; 

  switch (op) 
  { 
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
  std::cout << "\n"; 
  throw "";  
 } 
 
 catch (const char* msg) 
 { 
  std::cout << msg; 
  deleteMemory(matrix, n); 
 } 

 return 0; 
}
