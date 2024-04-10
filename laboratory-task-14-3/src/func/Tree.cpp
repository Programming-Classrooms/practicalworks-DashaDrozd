#include "Tree.hpp"

//Конструктор по умолчанию
Tree::Tree(): name("no name"),age(1),typeOfTree(treeType::DECIDUOUS)
{
}

//Конструктор с параметрами
Tree::Tree(std::string initName, int32_t initAge, treeType initTreeType): name(initName), age(initAge), typeOfTree(initTreeType)
{
}

//Конструктор копирования
Tree::Tree(const Tree &rhs): name(rhs.name), age(rhs.age), typeOfTree(rhs.typeOfTree)
{
}

//Деструктор
Tree::~Tree()
{
}

//Сеттеры
void Tree::setName(std::string initName)
{
    this->name = initName;
}

void Tree::setAge(int32_t initAge)
{
    this->age = initAge;
}

void Tree::setTreeType(treeType initType)
{
    this->typeOfTree = initType;
}

//Геттеры
std::string Tree::getName() const
{
    return this->name;
}

int32_t Tree::getAge() const
{
    return this->age;
}

treeType Tree::getTreeType() const
{
    return this->typeOfTree;
}

//Перегрузка вывода
std::ostream& operator<<(std::ostream& out, const Tree& rhs)
{
    out << "Name: " << rhs.name << '\n';
    out << "Age: " << rhs.age << '\n';

    switch(rhs.typeOfTree)
    {
        case treeType::CONIFEROUS:
        out << "Type is coniferous\n";
        break;
        
        case treeType::DECIDUOUS:
        out << "Type is deciduous\n";
        break;
    }

    return out;
}

//Перегрузка метода для вывода
void Tree::print(std::ostream &out) const
{
    out << *this;
}
