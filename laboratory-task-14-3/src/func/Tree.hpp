#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>

enum class treeType {
    CONIFEROUS,
    DECIDUOUS,
};

class Tree {
    protected:
    std::string name;
    int32_t age;
    treeType typeOfTree;
    public:
    Tree();
    Tree(std::string , int32_t, treeType );
    Tree (const Tree&);
    ~Tree();

    void setName(std::string);
    void setAge(int32_t);
    void setTreeType(treeType);

    std::string getName() const;
    int32_t getAge() const;
    treeType getTreeType() const;

    friend std::ostream& operator<<(std::ostream&, const Tree&);
    virtual void print(std::ostream&) const = 0;

};
#endif