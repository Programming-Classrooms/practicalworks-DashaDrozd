#include "gtest/gtest.h"
#include <sstream>
#include <set>
#include <string>

#include "../func/func.hpp"

TEST(WriteFishDataTest, EmptyFishSet) {
    std::set<std::string> fishSet = {};
    std::stringstream file;
    writeFishData(file, fishSet);
    EXPECT_EQ(file.str(), "\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}