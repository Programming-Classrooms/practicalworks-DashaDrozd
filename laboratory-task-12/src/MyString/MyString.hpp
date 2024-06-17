#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <stdexcept>

class MyString
{
private:
	char* str;
	size_t size;
public:
	MyString();
	MyString(const char* );
	MyString(const MyString&);
	~MyString();

	size_t getSize() const;
	void setSize(int);

	MyString& operator=(const MyString& );
	bool operator==(const MyString&) const;
	bool operator <(const MyString&);
	MyString operator+(const MyString&);
	MyString operator+=(const MyString&);

	friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);
};

#endif // !MYSTRING_HPPfndef 
