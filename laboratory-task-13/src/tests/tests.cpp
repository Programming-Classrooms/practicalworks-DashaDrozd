#include <gtest/gtest.h>
#include <sstream>
#include "../Fraction/Fraction.h" 
#include "../Matrix/Matrix.h" 

TEST(FractionTest, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(f.GetN(), 0);
    EXPECT_EQ(f.GetD(), 1);
}

TEST(FractionTest, ParameterizedConstructor) {
    Fraction f(3, 5);
    EXPECT_EQ(f.GetN(), 3);
    EXPECT_EQ(f.GetD(), 5);
}

TEST(FractionTest, CopyConstructor) {
    Fraction f1(3, 5);
    Fraction f2(f1);
    EXPECT_EQ(f2.GetN(), f1.GetN());
    EXPECT_EQ(f2.GetD(), f1.GetD());
}

TEST(FractionTest, SettersAndGetters) {
    Fraction f;
    f.SetN(4);
    f.SetD(7);
    EXPECT_EQ(f.GetN(), 4);
    EXPECT_EQ(f.GetD(), 7);
}

TEST(FractionTest, Addition) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 + f2;
    EXPECT_EQ(result.GetN(), 5);
    EXPECT_EQ(result.GetD(), 6);
}

TEST(FractionTest, Subtraction) {
    Fraction f1(3, 4);
    Fraction f2(1, 4);
    Fraction result = f1 - f2;
    EXPECT_EQ(result.GetN(), 1);
    EXPECT_EQ(result.GetD(), 2);
}

TEST(FractionTest, Multiplication) {
    Fraction f1(2, 3);
    Fraction f2(3, 4);
    Fraction result = f1 * f2;
    EXPECT_EQ(result.GetN(), 1);
    EXPECT_EQ(result.GetD(), 2);
}

TEST(FractionTest, Division) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result = f1 / f2;
    EXPECT_EQ(result.GetN(), 2);
    EXPECT_EQ(result.GetD(), 3);
}

TEST(FractionTest, Equality) {
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    EXPECT_EQ(f1, f2);
}

TEST(FractionTest, Inequality) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    EXPECT_NE(f1, f2);
}


TEST(FractionTest, NotEqualOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3(3, 4);

    EXPECT_NE(f1, f2); // Ожидаем, что f1 не равно f2
    EXPECT_NE(f1, f3); // Ожидаем, что f1 не равно f3
    EXPECT_NE(f2, f3); // Ожидаем, что f2 не равно f3
}


TEST(FractionTest, UnaryNegation) {
    Fraction f(3, 4);
    Fraction result = -f;
    EXPECT_EQ(result.GetN(), -3);
    EXPECT_EQ(result.GetD(), 4);
}

TEST(FractionTest, Reciprocal) {
    Fraction f(3, 4);
    Fraction result = ~f;
    EXPECT_EQ(result.GetN(), 4);
    EXPECT_EQ(result.GetD(), 3);
}

TEST(FractionTest, CastToDouble) {
    Fraction f(3, 4);
    Fraction result = f.cast();
    EXPECT_DOUBLE_EQ(static_cast<double>(result.GetN()) / result.GetD(), 0.75);
}

TEST(FractionTest, InputOutput) {
    Fraction f;
    std::stringstream ss;
    ss << "5 6";
    ss >> f;
    EXPECT_EQ(f.GetN(), 5);
    EXPECT_EQ(f.GetD(), 6);
}

TEST(MatrixTest, DefaultConstructor) {
    Matrix m;
    EXPECT_EQ(m.getColumns(), 1);
    EXPECT_EQ(m.getRows(), 1);
    EXPECT_EQ(m[0][0], 0);
}

TEST(MatrixTest, ParameterizedConstructor) {
    Matrix m(3, 2);
    EXPECT_EQ(m.getColumns(), 3);
    EXPECT_EQ(m.getRows(), 2);
    EXPECT_EQ(m[0][0], 0);
}

TEST(MatrixTest, CopyConstructor) {
    Matrix m1(2, 3);
    m1[0][0] = 1;
    Matrix m2(m1);
    EXPECT_EQ(m2.getColumns(), 2);
    EXPECT_EQ(m2.getRows(), 3);
    EXPECT_EQ(m2[0][0], 1);
}

TEST(MatrixTest, AssignmentOperator) {
    Matrix m1(2, 2);
    m1[0][0] = 1;
    Matrix m2;
    m2 = m1;
    EXPECT_EQ(m2.getColumns(), 2);
    EXPECT_EQ(m2.getRows(), 2);
    EXPECT_EQ(m2[0][0], 1);
}

TEST(MatrixTest, Addition) {
    Matrix m1(2, 2);
    m1[0][0] = 1;
    Matrix m2(2, 2);
    m2[0][0] = 2;
    Matrix result = m1 + m2;
    EXPECT_EQ(result[0][0], 3);
}

TEST(MatrixTest, Subtraction) {
    Matrix m1(2, 2);
    m1[0][0] = 3;
    Matrix m2(2, 2);
    m2[0][0] = 1;
    Matrix result = m1 - m2;
    EXPECT_EQ(result[0][0], 2);
}

TEST(MatrixTest, ScalarMultiplication) {
    Matrix m(2, 2);
    m[0][0] = 1;
    Matrix result = m * 2;
    EXPECT_EQ(result[0][0], 2);
}

TEST(MatrixTest, ScalarDivision) {
    Matrix m(2, 2);
    m[0][0] = 4;
    Matrix result = m / 2;
    EXPECT_EQ(result[0][0], 2);
}

// TEST(MatrixTest, Equality) {
//     Matrix m1(2, 2);
//     m1[0][0] = 1;
//     Matrix m2(2, 2);
//     m2[0][0] = 1;
//     EXPECT_EQ(m1, m2);
// }

// TEST(MatrixTest, Inequality) {
//     Matrix m1(2, 2);
//     m1[0][0] = 1;
//     Matrix m2(2, 2);
//     m2[0][0] = 2;
//     EXPECT_NE(m1, m2);
// }

TEST(MatrixTest, InputOutput) {
    Matrix m;
    std::stringstream ss;
    ss << "2 2\n1 2\n3 4\n";
    ss >> m;
    EXPECT_EQ(m.getColumns(), 2);
    EXPECT_EQ(m.getRows(), 2);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[0][1], 2);
    EXPECT_EQ(m[1][0], 3);
    EXPECT_EQ(m[1][1], 4);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}