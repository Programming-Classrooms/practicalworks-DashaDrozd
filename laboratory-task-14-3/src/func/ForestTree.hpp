#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "Tree.hpp"
#include <iostream>


class ForestTree:public Tree{
    private:
    int32_t amountOfTree;
    public:
    ForestTree();
    ForestTree(std::string , int32_t, treeType,int32_t);
    ForestTree (const ForestTree&);
    ~ForestTree();

    void setAmountOfTree(int32_t); 

    int32_t getAmountOfTree() const;

    friend std::ostream& operator<<(std::ostream&, const ForestTree&);
    void print(std::ostream&) const override;

};
#endif