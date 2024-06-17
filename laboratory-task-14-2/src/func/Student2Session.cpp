#include "Student2Session.h"

//Конструктор с параметрами
Student2Session::Student2Session(
    std::string initName, 
    int32_t initCourse, 
    int32_t initGroup,
     const int32_t recordNumber, 
     int32_t* arr,int32_t* arr2): Student1Session(initName, initCourse, initGroup, recordNumber,arr)
{
    for(size_t i = 0;i < 5; ++i){
        this->marksSecondSession[i] = arr[i];
    }
}

//Конструктор копирования
Student2Session::Student2Session(const Student2Session & rhs): Student1Session(rhs)
{
    for(size_t i = 0;i < 5; ++i){
        this->marksSecondSession[i] = rhs.marksSecondSession[i];
    }
}

//Деструктор
Student2Session::~Student2Session()
{
}

//Сеттер
void Student2Session::setMarks(int32_t* arr)
{
    for(size_t i = 0;i < 5; ++i){
        this->marksSecondSession[i] = arr[i];
    }
}

//Геттер
int32_t* Student2Session::getMarks()
{
    int32_t temp[5];
    for(size_t i = 0;i < 5; ++i){
        temp[i] = this->marksSecondSession[i];
    }   
    return temp; 
}

//Метод вывода
void Student2Session::print(std::ostream &out) const
{
    out << *this;
}

double Student2Session::AverageMark()
{
    double average = 0 ;
    for(size_t i = 0;i < 4; ++i){
        average += marksSecondSession[i];
    }
    for(size_t i = 0;i < 5; ++i){
        average += marksSecondSession[i];
    }   
    return static_cast<double>(average)/ 9;
}

//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Student2Session& rhs)
{
    rhs.Student2::print(out);
    out << "Marks: ";
    for(size_t i = 0; i < 5; ++i){
        out << rhs.marksSecondSession[i] << " ";
    }

    return out;
}
