#include <iostream>
#include <cstring>

bool isFullString(char* string)
{
  int length = std::strlen(string);  
  bool isFullString;
  for (size_t i = 0; i < length; ++i) {
    if (isalnum(string[i])) {
      isFullString = true;
    }
    else {
      isFullString = false;
    }
  }
  if (isFullString) {
    return true;
  }
  else {
    return false;
  }
}


bool isPalindrome(const char* word) {
    int length = std::strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}

void findPalindromes(const char* str, char* result) {
    const char* delimiter = " ";
    char* token = std::strtok(const_cast<char*>(str), delimiter);
    char* palindromes[100];
    int count = 0;

    while (token != nullptr) {
        if (isPalindrome(token)) {
            palindromes[count] = token;
            count++;
        }
        token = std::strtok(nullptr, delimiter);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (std::strlen(palindromes[i]) > std::strlen(palindromes[j])) {
                std::swap(palindromes[i], palindromes[j]);
            }
        }
    }

    std::strcpy(result, "");
    for (int i = 0; i < count; i++) {
        std::strcat(result, palindromes[i]);
        std::strcat(result, delimiter);
    }
}

int main() {
    char string[300]; 
    std::cout<<"Enter the string: ";
    std::cin.getline(string,300);
    isFullString(string);
    char result[100] = "";
    findPalindromes(string, result);
    std::cout <<"the result: " <<result << std::endl;
    return 0;
}