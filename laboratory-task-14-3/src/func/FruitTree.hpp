#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "Tree.hpp"
#include <iostream>


class FruitTree:public Tree{
    private:
    int32_t weight;
    int32_t storageDuration;
    public:
    FruitTree();
    FruitTree(std::string , int32_t, treeType, int32_t, int32_t);
    FruitTree (const FruitTree&);
    ~FruitTree();

    void setWeight(int32_t);
    void setDuration(int32_t); 

    int32_t getWeight() const;
    int32_t getDuration() const;

    friend std::ostream& operator<<(std::ostream&, const FruitTree&);
    void print(std::ostream&) const override;

};
#endif