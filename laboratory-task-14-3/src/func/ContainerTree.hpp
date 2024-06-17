#include "../func/Tree.hpp"
#include "../func/ForestTree.hpp"
#include "../func/FruitTree.hpp"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class TreeContainer {
private:
    std::vector<Tree*> trees;
public:
    TreeContainer(size_t = 0);

    size_t getSize() const;

    void addTree(Tree*);

    void printTrees(std::ostream&) const;

    int32_t countTreesType(treeType ) const;

    int32_t  countTreesKind(Tree*) const;
    
    bool compareTrees(Tree*, Tree*);

    void sortTrees();

    void readFromFile(std::ifstream&);

    //void checkFile(std::ifstream&);
};