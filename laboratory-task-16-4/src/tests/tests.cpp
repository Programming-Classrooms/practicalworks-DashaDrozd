#include "../func/func.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(MatrixOperationsTest, FillMatrixTest) {
    std::vector<std::vector<int>> matrix;
    size_t rows = 3, columns = 3;
    fillMatrix(matrix, rows, columns);
    ASSERT_EQ(matrix.size(), rows);
    ASSERT_EQ(matrix[0].size(), columns);
}

TEST(MatrixOperationsTest, FindMaxElementTest) {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    size_t rows = 3, columns = 3;
    size_t rowInd = 0, columnInd = 0;
    findMaxElement(matrix, rows, columns, rowInd, columnInd);
    ASSERT_EQ(rowInd, 2);
    ASSERT_EQ(columnInd, 2);
}

TEST(MatrixOperationsTest, DeleteMaxElementColAndRowTest) {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    size_t rows = 3;
    size_t rowInd = 2, columnInd = 2;
    deletMaxElementColAndRow(matrix, rows, rowInd, columnInd);
    ASSERT_EQ(matrix.size(), 2);
    ASSERT_EQ(matrix[0].size(), 2);
}

TEST(MatrixOperationsTest, SortBySumOfRowsElementsTest) {
    std::vector<std::vector<int>> matrix = {
        {3, 3, 3},
        {1, 1, 1},
        {2, 2, 2}
    };
    sortBySumOfRowsElements(matrix);
    ASSERT_EQ(matrix[0][0], 1);
    ASSERT_EQ(matrix[1][0], 2);
    ASSERT_EQ(matrix[2][0], 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
