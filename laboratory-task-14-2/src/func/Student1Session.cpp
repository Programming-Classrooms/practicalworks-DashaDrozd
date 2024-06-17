#include "Student1Session.h"

//Конструктор с параметрами
Student1Session::Student1Session(
    std::string initName, 
    int32_t initCourse, 
    int32_t initGroup,
     const int32_t recordNumber, 
     int32_t* arr): Student2(initName, initCourse, initGroup, recordNumber)
{
    for(size_t i = 0;i < 4; ++i){
        this->marks[i] = arr[i];
    }
}

//Конструктор копирования
Student1Session::Student1Session(const Student1Session & rhs): Student2(rhs)
{
    for(size_t i = 0;i < 4; ++i){
        this->marks[i] = rhs.marks[i];
    }
}

//Деструктор
Student1Session::~Student1Session()
{
}

//Сеттер
void Student1Session::setMarks(int32_t* arr)
{
    for(size_t i = 0;i < 4; ++i){
        this->marks[i] = arr[i];
    }
}

//Геттер
int32_t* Student1Session::getMarks()
{
    int32_t temp[4];
    for(size_t i = 0;i < 4; ++i){
        temp[i] = this->marks[i];
    }   
    return temp; 
}

//Метод вывода
void Student1Session::print(std::ostream &out) const
{
    out << *this;
}

double Student1Session::AverageMark()
{
    double average = 0 ;
    for(size_t i = 0;i < 4; ++i){
        average += marks[i];
    }   
    return static_cast<double>(average)/ 4;
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Student1Session& rhs)
{
    rhs.Student2::print(out);
    out << "Marks: ";
    for(size_t i = 0;i < 4; ++i){
        out << rhs.marks[i] <<" ";
    }

    return out;
}
