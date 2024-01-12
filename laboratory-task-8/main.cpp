/*
	Строка состоит из слов, разделённых знаками препинания. За один
	просмотр символов строки найти все слова, представляющие собой простые
	числа и занести их в новую строку. Слова в новой строке должны
	разделяться ровно одним пробелом.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <exception>
#include <Windows.h>


bool isFullString(char* string)
{
    bool isEmpty = 1;
    if (string == nullptr || *string == '\0') {
       isEmpty = 0;
    }

    while (*string != '\0') {
        if (!std::isspace(*string)) {
            isEmpty = 1;
        }
        string++;
    }

    if (!isEmpty) {
        isEmpty = 0;
    }
    return isEmpty;
}


bool isPalindrome(const char* word)
{
    size_t length = std::strlen(word);

    for (size_t i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void findPalindromes(const char* str, char* result)
{
    const char* delimiter = " ";
    std::string strCopy;
    strcpy(strCopy, str);
    char* token = std::strtok(strCopy, delimiter);
    char* palindromes[300];
    size_t count = 0;

    while (token != nullptr) {
        if (isPalindrome(token)) {
            palindromes[count] = token;
            count++;
        }

        token = std::strtok(nullptr, delimiter);
    }
    
    size_t numOfPalindromes = count - 1;

    if (count == 0) {
        throw std::exception ("Palindroms are not exist\n");
    }

    for (size_t i = 0; i < numOfPalindromes; i++) {
        for (size_t j = i + 1; j < count; j++) {
            if (std::strlen(palindromes[i]) > std::strlen(palindromes[j])) {
                std::swap(palindromes[i], palindromes[j]);
            }
        }
    }

    std::strcpy(result, "");
    
    for (size_t i = 0; i < count; i++) {
        std::strcat(result, palindromes[i]);
        std::strcat(result, delimiter);
    }
    
}

int main() {
      SetConsoleCP(1251);                
      SetConsoleOutputCP(1251);
      setlocale(LC_ALL, "1251");

    try {
      
        char string[300];
        std::cout << "Enter the string: ";
        std::cin.getline(string, 300);

       if(!isFullString(string)) {
            std::exception ("String is empty!\n");
       } 

        char result[300] = "";
        findPalindromes(string, result);
        std::cout << "the result: " << result << '\n';
    }

    catch (std::exception e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

