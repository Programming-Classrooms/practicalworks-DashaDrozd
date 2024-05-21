#include "func.hpp"

void checkFile(std::fstream& file)
{
    if(!file.good())
    {
        throw std::runtime_error("File is not exist!\n");
    }

    if(!file)
    {
        throw std::runtime_error("File is not open!\n");
    }

    if(file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!\n");
    }
}

std::vector<Student> readStudentsFromFile(std::fstream& file)
{
    std::vector<Student> students;
    std::string line;

    while(std::getline(file, line))
    {
        Student stud;
        std::stringstream ss(line);
        ss >> stud.surname >> stud.name >> stud.lastName  >> stud.course >> stud.group;
        students.push_back(stud);
    }

    students.pop_back();
    file.close();
    return students;
}

void writeToFile (std::ofstream& fout, std::vector<Student>& students)
{
    for(size_t i = 0; i < students.size(); ++i)
    {
        fout << students[i].surname << " " << students[i].name << " " << students[i].lastName << " " << students[i].course << " " << students[i].group << '\n';
    }

    fout.close();
}

bool compareByLastName(const Student& first, const Student& second) {
    return first.surname < second. surname;
}

bool compareByGroupAndCourse(const Student& first, const Student& second) {

    if(first.course != second.course)
    {
        return first.course < second.course;
    }

    if (first.group != second.group)
    {
        return first.group < second.group;
    }

    return first.surname < second.surname;

}
