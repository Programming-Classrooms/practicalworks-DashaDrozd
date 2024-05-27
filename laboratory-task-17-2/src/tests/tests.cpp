#include "gtest/gtest.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "../func/func.hpp"

// Тесты для функции checkFile
TEST(FileCheckTest, NonExistentFile) {
    std::ifstream file("nonexistent.txt");
    EXPECT_THROW(checkFile(file), std::runtime_error);
}

TEST(FileCheckTest, EmptyFile) {
    std::ofstream outFile("empty.txt");
    outFile.close();
    std::ifstream file("empty.txt");
    EXPECT_THROW(checkFile(file), std::runtime_error);
}

TEST(FileCheckTest, GoodFile) {
    std::ofstream outFile("good.txt");
    outFile << "This is a test file.";
    outFile.close();
    std::ifstream file("good.txt");
    EXPECT_NO_THROW(checkFile(file));
}

// Тесты для функции toLower
TEST(ToLowerTest, EmptyString) {
    std::string str = "";
    toLower(str);
    EXPECT_EQ(str, "");
}

TEST(ToLowerTest, MixedCaseString) {
    std::string str = "HeLLo WoRLd";
    toLower(str);
    EXPECT_EQ(str, "hello world");
}

TEST(ToLowerTest, AllUpperCaseString) {
    std::string str = "TESTING";
    toLower(str);
    EXPECT_EQ(str, "testing");
}

// Тесты для функции splitIntoWords
TEST(SplitIntoWordsTest, EmptyString) {
    std::vector<std::string> result = splitIntoWords("");
    EXPECT_TRUE(result.empty());
}

TEST(SplitIntoWordsTest, SingleWord) {
    std::vector<std::string> result = splitIntoWords("word");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "word");
}

TEST(SplitIntoWordsTest, DelimitersOnly) {
    std::vector<std::string> result = splitIntoWords(" ;:/,.-_");
    EXPECT_TRUE(result.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
