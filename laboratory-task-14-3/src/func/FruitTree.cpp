#include "FruitTree.hpp"
//Конструктор по умолчанию
FruitTree::FruitTree(): Tree(), weight(1), storageDuration(1)
{
}

//Конструктор с параметрами
FruitTree::FruitTree(std::string initName, int32_t initAge, treeType initType, int32_t initWeight, int32_t initDuration): Tree(initName, initAge, initType), weight(initWeight), storageDuration(initDuration)
{
}

//Конструктор копирования
FruitTree::FruitTree(const FruitTree &rhs): Tree(rhs), weight(rhs.weight), storageDuration(rhs.storageDuration)
{
}

//Деструктор
FruitTree::~FruitTree()
{
}

//Сеттеры
void FruitTree::setWeight(int32_t initWeight)
{
    this->weight = initWeight;
}

void FruitTree::setDuration(int32_t initDuration)
{ 
    this->storageDuration = initDuration;
}

//Геттеры
int32_t FruitTree::getWeight() const
{
    return this->weight;
}

int32_t FruitTree::getDuration() const
{
    return this->storageDuration;
}

std::ostream &operator<<(std::ostream &out, const FruitTree &rhs)
{
    rhs.Tree::print(out);
    out << "Harvest weight: " << rhs.weight;
    out << "\nStorage duration: " << rhs.storageDuration;
    return out;
}

void FruitTree::print(std::ostream &out) const
{
    out << *this << '\n';
}