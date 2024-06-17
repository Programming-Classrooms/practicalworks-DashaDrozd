#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <exception>
#include <sstream> 
#include <algorithm>

struct Student
{
    std::string surname;
    std::string name;
    std::string lastName;
    int32_t course;
    int32_t group;
};

void checkFile(std::fstream&);
std::vector<Student> readStudentsFromFile(std::fstream&);
void writeToFile (std::ofstream&, std::vector<Student>&);
bool compareByLastName(const Student&, const Student&);
bool compareByGroupAndCourse(const Student&, const Student&);
//void sortByCourseGroupAndSurname(std::vector<Student>&);

#endif // !1