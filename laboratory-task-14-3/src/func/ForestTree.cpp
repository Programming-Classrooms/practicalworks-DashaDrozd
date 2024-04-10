#include "ForestTree.hpp"

//Конструктор по умолчанию
ForestTree::ForestTree(): Tree(),amountOfTree(1)
{
}

//Конструктор с параметрами
ForestTree::ForestTree(std::string initName, int32_t initAge, treeType initType, int32_t initAmountOfTree): Tree(initName, initAge, initType), amountOfTree(initAmountOfTree)
{
}

//Конструктор копирования
ForestTree::ForestTree(const ForestTree &rhs): Tree(rhs), amountOfTree(rhs.amountOfTree)
{
}

//Деструктор
ForestTree::~ForestTree()
{
}

//Сеттеры
void ForestTree::setAmountOfTree(int32_t initAmountOfTree)
{
    this->amountOfTree = initAmountOfTree;
}

//Геттеры
int32_t ForestTree::getAmountOfTree() const
{
    return this->amountOfTree;
}

std::ostream &operator<<(std::ostream &out, const ForestTree &rhs)
{
    rhs.Tree::print(out);
    out << "Amount of tree: " << rhs.amountOfTree;
    return out;
}

void ForestTree::print(std::ostream &out) const
{
    out << *this<< '\n';
}