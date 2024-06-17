#include "../func/ContainerTree.hpp"
//#include  "//src/files/trees.txt"
#include <iostream>
#include <fstream>

void checkFile(std::ifstream& file)
    {
        if (!file.good()) {
            throw std::runtime_error("File is not exist!");
        }
        if (!file) {
            throw std::runtime_error("File is not open!");
        }
        if (file.peek() == EOF) {
            throw std::runtime_error("File is empty!");
        }
    }

int main() {
    
    try {
    
    TreeContainer container;
    std::ifstream file("src/files/trees.txt");
	checkFile(file);
    container.readFromFile(file);

    container.printTrees(std::cout);

    std::cout << "Number of deciduous trees: " << container.countTreesType(treeType::DECIDUOUS) << std::endl;
    std::cout << "Number of coniferous trees: " << container.countTreesType(treeType::CONIFEROUS) << std::endl;
    std::cout << "Number of forest trees: " << container.countTreesKind(new ForestTree()) << std::endl;
    std::cout << "Number of fruit trees: " << container.countTreesKind(new FruitTree()) << std::endl;

    container.sortTrees();
    std::cout << "Sorted trees:" << std::endl;
    container.printTrees(std::cout);
    }
    catch(std::runtime_error e)
    {
        std::cout << e.what() <<'\n';
    }
    return 0;
}
