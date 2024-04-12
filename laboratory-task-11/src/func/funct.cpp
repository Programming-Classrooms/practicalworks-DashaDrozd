#include "../func/funct.hpp"
#include <string> 
#include <algorithm> 
 
 
void checkFile(std::ifstream& file) 
{ 
 if (!file.good()) 
 { 
  throw std::runtime_error("File is not exist!\n"); 
 } 
 if (!file) 
 { 
  throw std::runtime_error("File is not open!\n"); 
 } 
 if (file.peek() == EOF) 
 { 
  throw std::runtime_error("File is empty!\n"); 
 } 
} 
 
bool isNumb(std::string& word) 
{ 
 size_t size = word.size(); 
 if (word[0] == '-' || isdigit(word[0])) { 
  for (size_t i = 1; i < size; ++i) { 
   if (!isdigit(word[i])) { 
    return false; 
   } 
  } 
  return true; 
 } 
 return false; 
} 
 
 
void printArr(int32_t* arr, const size_t& size) 
{ 
 for (size_t i = 0; i < size; ++i) 
 { 
  std::cout << arr[i] << ' '; 
 } 
 
 std::cout << '\n'; 
} 
 
 
std::string findNumbs(std::ifstream& file, std::string& line, std::string& delims, int32_t& count) 
{ 
 std::string word; 
 std::string numbs; 
 while (getline(file, line)) 
 { 
  std::string::size_type begInd, endInd; 
  begInd = line.find_first_not_of(delims); 
 
  while (begInd != std::string::npos) 
  { 
   endInd = line.find_first_of(delims, begInd);; 
   word = line.substr(begInd, endInd - begInd); 
 
   if (isNumb(word)) 
   { 
    numbs += word + " "; 
    ++count; 
   } 
 
   begInd = line.find_first_not_of(delims, endInd); 
  } 
 } 
 
 if (count == 0) 
 { 
  throw std::runtime_error("Numbers are not founded!\n"); 
 } 
 
 return numbs; 
} 
 
 
void sortNumbers(int32_t* arr, int32_t* copyArr, int32_t& size) 
{ 
 size_t j = 0; 
 
 for (size_t i = 0; i < size; ++i) 
 { 
  if ((arr[i] & 1) != 1) 
  { 
   copyArr[j++] = arr[i]; 
  } 
 
 } 
 for (size_t i = 0; i < size; ++i) 
 { 
  if ((arr[i] & 1) == 1) 
  { 
   copyArr[j++] = arr[i]; 
  } 
 
 } 
} 
 
bool isSurname(std::string& word) 
{ 
 size_t size = word.size(); 
 if (isupper(word[0])) { 
  for (size_t i = 1; i < size; ++i) { 
   if (!isalpha(word[i])) { 
    return false; 
   } 
  } 
  return true; 
 } 
 return false; 
} 
 
 
std::string findSurnames(std::ifstream& file, std::string& line, std::string& delims, int32_t& count, std::string* surname) 
{ 
 std::string word; 
 std::string surnames; 
 size_t i = 0; 
 while (std::getline(file, line)) 
 { 
  std::string::size_type begInd, endInd; 
  begInd = line.find_first_not_of(delims); 
 
  while (begInd != std::string::npos) 
  { 
   endInd = line.find_first_of(delims, begInd);; 
   word = line.substr(begInd, endInd - begInd); 
 
   if (isSurname(word)) 
   { 
    surname[i++] = word; 
    ++count; 
   } 
 
   begInd = line.find_first_not_of(delims, endInd); 
  } 
 } 
 
  if (count == 0) 
  { 
  throw std::runtime_error("Surnames are not founded!\n"); 
  }
 return surnames; 

} 
 
std::string toUpper(std::string word) 
{ 
 for (size_t i = 0; i < word.size(); ++i) { 
  word[i] = std::toupper(word[i]); 
 } 
 return word; 
} 
 
bool comp(std::string word1, std::string word2) 
{ 
 word1 = toUpper(word1); 
 word2 = toUpper(word2); 
 return (word1 < word2); 
} 
 
void qsortString(std::string* arr, size_t left, size_t right) 
{ 
 size_t begin = left; 
 size_t end = right; 
 size_t mid = (left + right) / 2; 
 
 
 while (end > begin) { 
  while (comp(arr[begin], arr[mid])) { 
   ++begin; 
  } 
  while (comp(arr[mid], arr[end])) { 
   --end; 
  } 
  if (begin < end) { 
   std::swap(arr[end], arr[begin]); 
   --end; 
   ++begin; 
  } 
 } 
 
 if (end < right) { 
  qsortString(arr, right, end); 
 } 
 if (begin > left) { 
  qsortString(arr, begin, left); 
 } 
} 
 
void printString(std::string* arr, const size_t& size) 
{ 
 for (size_t i = 0; i < size; ++i) 
 { 
  std::cout << arr[i] << ' '; 
 } 
 
 std::cout << '\n'; 
} 
 
 
void fillChil(Employee* employee, std::string* surnames, int32_t* allNumbers, int32_t& size) { 
 size_t counter = 0, i = 0; 
 while (i < size) { 
  if (allNumbers[i] <= 9)
{ 
   employee[counter].children = allNumbers[i]; 
   counter++; 
   i++; 
  } 
  else { 
   ++i; 
  } 
 } 
  while (counter < size) 
  { 
   std::cout << " Enter count of children for - " << counter << "\n"; 
   std::cin >> employee[counter].children; 
   counter++; 
  } 
 
 for (size_t j = 0; j < size; ++j) { 
   
  employee[j].surname = surnames[j]; 
 } 
} 
 
void print(std::ofstream& out, Employee* employee, size_t& size) { 
 for (size_t i = 0; i < size; ++i) 
 { 
  out << employee[i].surname <<  " " << employee[i].children; 
 } 
}

bool comp(Employee employees1, Employee employees2) { 
	if (toUpper(employees1.surname) == toUpper(employees2.surname)) {
  return employees1.children > employees1.children; }
 return toUpper(employees1.surname) > toUpper(employees2.surname);
 }

 void swapString(Employee* employees,size_t sizeText) {
 std::swap(employees[0].surname, employees[sizeText-1].surname);
  std::swap(employees[0].children, employees[sizeText-1].children);
}

void outputInTxtFile(Employee* employees ,size_t sizeText) { 
 std::cout << std::endl; 
 std::ofstream fout("src/files/result.txt"); 
 for (size_t i = 0; i < sizeText; ++i) { 
  fout << employees[i].surname << " " << employees[i].children << std::endl; 
 } 
 std::cout << "Output in txt File good"; 
} 
 
void outputInBinFile(Employee* employees, size_t sizeText) { 
 std::ofstream fbin("result.bin", std::ios::binary); 
 for (size_t i = 0; i < sizeText; ++i) { 
  fbin.write((char*)&employees[i], sizeof(Employee)); 
 } 
 std::cout << std::endl <<std::endl << "output in BIN file good"; 
 fbin.close(); 
}
