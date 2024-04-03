#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#include "MyString.hpp"


MyString::MyString(const char* src)
{
    this->size = std::strlen(src);
    this->str = new char[size + 1];
    std::strcpy(str, src);
}

MyString::MyString(): str(nullptr), size(0)
{

}

MyString::MyString(const MyString& src): size (src.size), str (new char[size + 1])
{
    std::strcpy(str, src.str);
}

MyString::~MyString()
{
    if (this->str != nullptr) {
        delete[] this->str;
    }
}


size_t MyString::getSize() const
{
    return size;
}

void MyString::setSize(int size)
{
    if (size <= 0) {
        throw std::invalid_argument("wrong size\n");
    }
}

MyString& MyString::operator=(const MyString& src)
{
    if (this == &src)
        return *this;

    if (size != src.size || size == 0)
    {
        if (str != nullptr) {
            delete[] str;
        }
        size = src.size;
        str = new char[size + 1];
    }
    strcpy(str, src.str);
    return *this;
}

std::ostream& operator<<(std::ostream& out, MyString& src)
{
    for (size_t i = 0; i < src.size; ++i) {
        out << src.str[i];
    }

    return out;
}

std::istream& operator>>(std::istream& in, MyString& src)
{
     for (size_t i = 0; i < src.size; ++i) {
        in >> src.str[i];
    }

    return in;
}

MyString MyString::operator+(const MyString& src)
{
    MyString temp;
    temp.size = size + src.size;
    temp.str = new char[temp.size + 1];
    strcpy(temp.str, str);
    strcat(temp.str, src.str);
    return temp;
}

MyString MyString::operator+=(const MyString& src)
{
    MyString temp;
    temp.size = size + src.size;
    temp.str = new char[temp.size + 1];
    strcpy(temp.str, str);
    strcat(temp.str, src.str);
    return temp;
}

bool MyString::operator<(const MyString& st)
{
    return strcmp(str, st.str) < 0;
}

bool MyString::operator==(const MyString& st) const
{
    return strcmp(str, st.str) == 0;
}
