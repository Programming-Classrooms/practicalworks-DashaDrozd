    #include "ContainerTree.hpp"

    TreeContainer::TreeContainer(size_t size): trees(std::vector<Tree *>(size, nullptr))
    {

    }

    size_t TreeContainer::getSize() const
    {
    return this->trees.size();
    }

    void TreeContainer::addTree(Tree *tree)
    {
        trees.push_back(tree);
    }

    void TreeContainer::printTrees(std::ostream& out) const {
            for (size_t i = 0; i < trees.size(); ++i) {
                trees[i]->print(std::cout); 
            }
        }


    int32_t TreeContainer::countTreesType(treeType typeOfTrees) const 
    {  
        int32_t counter = 0;
        for (size_t i = 0; i < trees.size(); ++i) {
            if (trees[i]->getTreeType() == typeOfTrees) {
                ++counter;
            }
        }
        return counter;
    }

    int32_t TreeContainer::countTreesKind(Tree* kindOfTrees) const 
    {
        int32_t counter = 0;
        size_t size = trees.size();
        if(dynamic_cast<ForestTree*>(kindOfTrees)){
             for (size_t i = 0; i < size; ++i) {
                    if (dynamic_cast<ForestTree*>(trees[i])) {
                        ++counter;
                }
            }
        }
       

        if(dynamic_cast<FruitTree*>(kindOfTrees)){
            for (size_t i = 0; i < size; ++i) {
                if (dynamic_cast<FruitTree*>(trees[i])) {
                    ++counter;
                }
            }
        }
         
        return counter;
    }

    bool TreeContainer::compareTrees(Tree* tree1, Tree* tree2) {
    if (tree1->getName() != tree2->getName()) {
        return tree1->getName() < tree2->getName();
    }
    return tree1->getAge() > tree2->getAge();
    }

    void TreeContainer::sortTrees() {
        for (size_t i = 1; i < trees.size(); ++i) {
            size_t j = i;
            while (j > 0 && compareTrees(trees[j - 1], trees[j])) {
                std::swap(trees[j - 1], trees[j]);
                --j;
            }
        }
    }

    void TreeContainer::readFromFile(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string kindOfTree;
            std::string type;
            ss >> type;
            if(type == "coniferous" || type == "deciduous"){
                ss >> kindOfTree;
                if (kindOfTree == "Forest") { 
                
                    std::string name;
                    int32_t age;
                    int32_t amountOfTree;
                    ss >> name >> age >> amountOfTree;
                    ForestTree* tree = new ForestTree(name, age, (type == "coniferous" ? treeType::CONIFEROUS : treeType::DECIDUOUS), amountOfTree);
                    trees.push_back(tree);
                } else if (kindOfTree == "Fruit") {
                    std::string name;
                    int32_t age;
                    int32_t weight;
                    int32_t storageDuration;
                    ss >> name >> age >> weight >> storageDuration;
                    FruitTree* tree = new FruitTree(name, age, (type == "coniferous" ? treeType::CONIFEROUS : treeType::DECIDUOUS),  weight, storageDuration);
                    trees.push_back(tree);
                } else {
                    throw std::runtime_error("Unknown type!!!!!!!!!!!!!");
                }
            }
        }

        file.close();
    }
