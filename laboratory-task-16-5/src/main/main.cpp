#include "../func/func.hpp"

int main()
{
    std::fstream file("src/files/Students.txt");
    checkFile(file);
    std::vector<Student>students = readStudentsFromFile(file);
    sort(students.begin(), students.end(), compareByLastName);
    std::ofstream fout("src/files/Fio.txt");
    writeToFile(fout,students);
    sort(students.begin(), students.end(), compareByGroupAndCourse);
    std::ofstream out("src/files/Group.txt");
    writeToFile(out,students);
    return 0;
}