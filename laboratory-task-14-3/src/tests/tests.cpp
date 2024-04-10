#include "gtest/gtest.h"
#include "../func/ContainerTree.hpp"
#include "../func/ForestTree.hpp"
#include <fstream>

TEST(TreeContainerTest, SizeTest)
{
    TreeContainer container;
    EXPECT_EQ(container.getSize(), 0);

    container.addTree(new ForestTree("Oak", 50, treeType::DECIDUOUS, 100));
    container.addTree(new FruitTree("Apple", 10, treeType::DECIDUOUS, 50, 30));
    container.addTree(new ForestTree("Pine", 30, treeType::CONIFEROUS, 80));

    EXPECT_EQ(container.getSize(), 3);
}

TEST(TreeContainerTest, CountTreesTypeTest)
{
    TreeContainer container;
    container.addTree(new ForestTree("Oak", 50, treeType::DECIDUOUS, 100));
    container.addTree(new FruitTree("Apple", 10, treeType::DECIDUOUS, 50, 30));
    container.addTree(new ForestTree("Pine", 30, treeType::CONIFEROUS, 80));

    EXPECT_EQ(container.countTreesType(treeType::DECIDUOUS), 2);
    EXPECT_EQ(container.countTreesType(treeType::CONIFEROUS), 1);
}

TEST(TreeContainerTest, SortTreesTest)
{
    TreeContainer container;
    container.addTree(new ForestTree("Oak", 50, treeType::DECIDUOUS, 100));
    container.addTree(new FruitTree("Apple", 10, treeType::DECIDUOUS, 50, 30));
    container.addTree(new ForestTree("Pine", 30, treeType::CONIFEROUS, 80));

    container.sortTrees();
}

TEST(ForestTreeTest, ConstructorWithParameters)
{
    ForestTree tree("Oak", 50, treeType::CONIFEROUS, 10);
    EXPECT_EQ(tree.getName(), "Oak");
    EXPECT_EQ(tree.getAge(), 50);
    EXPECT_EQ(tree.getTreeType(), treeType::CONIFEROUS);
    EXPECT_EQ(tree.getAmountOfTree(), 10);
}

TEST(ForestTreeTest, SetterAndGetters)
{
    ForestTree tree;
    tree.setName("Pine");
    tree.setAge(30);
    tree.setTreeType(treeType::CONIFEROUS);
    tree.setAmountOfTree(5);

    EXPECT_EQ(tree.getName(), "Pine");
    EXPECT_EQ(tree.getAge(), 30);
    EXPECT_EQ(tree.getTreeType(), treeType::CONIFEROUS);
    EXPECT_EQ(tree.getAmountOfTree(), 5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}