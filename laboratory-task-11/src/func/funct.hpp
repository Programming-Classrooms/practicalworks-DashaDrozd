#ifndef FUNCT
#define FUNCT
#include <iostream>
#include <string.h>
#include <fstream>
#include <string.h>
#include <stdexcept>

struct Employee {
	std::string surname;
	size_t children;
};

void checkFile(std::ifstream&);
bool isNumb(std::string&);
std::string findNumbs(std::ifstream&, std::string&, std::string&, int32_t&);
void printArr(int32_t*, const size_t&);
void sortNumbers(int32_t*, int32_t*, int32_t&);
std::string findSurnames(std::ifstream&, std::string&, std::string&, int32_t&, std::string*);
bool isSurname(std::string&);
std::string toUpper(std::string);
bool compairStr(std::string, std::string);
void qsortString(std::string*, size_t, size_t);
void printString(std::string*, const size_t&);
template <typename T> 
void universalQsort(T*, size_t, size_t, bool (*comp)(T, T));
void fillChil(Employee*, std::string*, int32_t*, int32_t&);
void print(std::ofstream&, Employee*, size_t&);
bool comp(Employee, Employee);
void swapString(Employee* ,size_t);
void outputInTxtFile(Employee*, size_t);
void outputInBinFile(Employee*, size_t); 

// template<typename T> 
// void selectionSort(T* arr, size_t size) 
// { 
//   for (size_t i = 0; i < size; ++i) 
//   { 
//    size_t minInd = i; 
//    for (size_t j = i + 1; j < size - 1; j++) 
//    { 
//     if (arr[j] < arr[minInd]) 
//     { 
//      minInd = j; 
//     } 
//    } 
//    if (minInd != i) 
//    { 
//     std::swap(arr[i], arr[minInd]); 
//    } 
//   } 
// } 
template<typename T>
void universalQsort(T* arr, size_t left, size_t right, bool (*comp)(T, T))
{
	size_t begin = left;
	size_t end = right;
	size_t mid = (left + right) / 2;

	T pivot = arr[mid];
	while (end > begin) {
		while (comp(arr[begin], pivot)) {  // arr[begin] < arr[mid]
			++begin;
		}
		while (comp(pivot, arr[end])) { // arr[end] > arr[mid]
			--end;
		}
		if (begin < end) {
			std::swap(arr[end], arr[begin]);
			--end;
			++begin;
		}
	}
	if (end < right) {
		universalQsort(arr, right, end, comp);
	}
	if (begin > left) {
		universalQsort(arr, begin, left, comp);
	}
}

#endif