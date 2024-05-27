   #include "Author.hpp"

    //Конструктор с параметрами
    Author::Author(std::string initLastName, std::string initFirstName, std::string initMiddleName): lastName(initLastName), firstName(initFirstName), middleName(initMiddleName) {
    }

    //Перегрузка оператора вывода
    std::ostream&  operator<<(std::ostream& out, const Author& author) {
        out << author.getLastName() << " " << author.getFirstName() << " " << author.getMiddleName();
        return out;
    }

    //Перегрузка оператора присваивания
    Author &Author::operator=(const Author &rhs)
    {
        if(this != &rhs)
        {
            lastName = rhs.lastName;
            firstName = rhs.firstName;
            middleName = rhs.middleName;

        }

        return *this;
    }

    //Перегрузка оператора ввода
    std::istream& operator>>(std::istream& in, Author &rhs)
    {
        in >> rhs.lastName >> rhs.firstName >> rhs.middleName;
        return in;
    }

    //Геттеры
    std::string Author::getLastName() const
    {
        return lastName;
    }

    std::string Author::getFirstName() const
    {
        return firstName;
    }

    std::string Author::getMiddleName() const
    {
        return middleName;
    }  
    
    //Перегрузка оператора сравнения
    bool Author::operator==(const Author &other) const
    {
        return this->lastName == other.lastName && this->firstName == other.firstName && this->middleName == other.middleName;
    }
    