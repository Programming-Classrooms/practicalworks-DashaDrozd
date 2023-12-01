#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
 
using std::cout; 
using std::cin; 
 
void fillKeyboard(int32_t** matrix, int32_t& size) 
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
 
void fillRand(int32_t** matrix, const int32_t& size) 
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
 
int32_t searchOfMaxInRightLowConer(int32_t** matrix, const int32_t& size) 
{ 
 int32_t max = matrix[0][size-1]; 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  for(size_t j = 0; j < size; ++j) 
  { 
   if (i > size - 1 - j && matrix[i][j] > max) 
   { 
    max = matrix[i][j]; 
   } 
  } 
 } 
 return max; 
} 
 
size_t maxInI(int32_t** matrix, const int32_t& size) 
{ 
 int32_t max = matrix[0][0]; 
 size_t indi = 0; 
 size_t indj = 0; 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   if (matrix[size-1-i][size-1-j] > max) 
   { 
    max = matrix[size-1-i][size-1-j]; 
    indi = size-1-i; 
   } 
  } 
 } 
 return indi; 
} 
 
size_t maxInJ(int32_t** matrix, const int32_t& size) 
{ 
 int32_t max = matrix[0][0]; 
 size_t indi = 0; 
 size_t indj = 0; 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  for (size_t j = 0; j < size; ++j) 
  { 
   if (matrix[size-1-i][size-1-j] > max) 
   { 
    max = matrix[size-1-i][size-1-j]; 
    indj = size-1-j; 
   } 
  } 
 } 
 return indj; 
} 
 
void maxElementInLeftCorner(int32_t** matrix, const int32_t& size) 
{ 
 if (matrix[maxInI(matrix, size)][maxInJ(matrix, size)] < 0)  
 { 
  throw "Maximum element is not positive!"; 
 } 
 for (int32_t i = 0; i < size ; ++i) 
 { 
    
  for (size_t j = 0; j <size; ++j) 
  {    
   std::swap(matrix[i][0],matrix[maxInI(matrix, size)][maxInJ(matrix, size)]); 
   std::swap(*matrix[j], *matrix[maxInJ(matrix, size)]); 
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
   fillKeyboard(matrix, n); 
   break; 
  case 1: 
   fillRand(matrix, n); 
   break; 
  default: 
   std::cout << "Input incorrect value.Get out of my program!"; 
   return 1; 
  } 
  printMatrix(matrix, n); 
  cout << "\nMaximum element of the lower right triangle of the matrix: " << searchOfMaxInRightCorner(matrix, n) << '\n'; 
  maxElementInLeftCorner(matrix, n); 
  std::cout << "\n"; 
  cout << maxInI(matrix, n) << maxInJ(matrix, n) << std::endl; 
  throw "";  
 } 
 
 catch (const char* msg) 
 { 
  std::cout << msg; 
  deleteMemory(matrix, n); 
   
 } 
 return 0; 
 
}
