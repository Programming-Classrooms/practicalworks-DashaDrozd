#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include "../func/funct.hpp" 

TEST(CheckFileTest, GoodFile) {
    std::ifstream file("src/files/test.txt");
    ASSERT_NO_THROW(checkFile(file));
}

TEST(IsNumbTest, ValidNumber) {
    std::string number = "123";
    ASSERT_TRUE(isNumb(number));
}

TEST(IsNumbTest, InvalidNumber) {
    std::string number = "abc";
    ASSERT_FALSE(isNumb(number));
}

TEST(FindNumbsTest, EmptyFile) {
    std::ifstream file("empty.txt");
    std::string line, delims;
    int32_t count = 0;
    ASSERT_THROW(findNumbs(file, line, delims, count), std::runtime_error);
}

TEST(IsSurnameTest, ValidSurname) {
    std::string surname = "Strashnov";
    ASSERT_TRUE(isSurname(surname));
}

TEST(IsSurnameTest, InvalidSurname) {
    std::string surname = "123";
    ASSERT_FALSE(isSurname(surname));
}

TEST(FindSurnamesTest, EmptyFile) {
    std::ifstream file("empty.txt");
    std::string line, delims;
    std::string surnames[0]={};
    int32_t count = 0;
    ASSERT_THROW(findSurnames(file, line, delims, count, surnames), std::runtime_error);
}

TEST(FillChilTest, FillingChildren) {
    Employee employees[3]; 
    std::string surnames[3] = {"Strashnov", "Malec", "Rubec"};
    int32_t allNumbers[] = {2, 3, 4, 5}; 
    int32_t size = 4;
    ASSERT_NO_THROW(fillChil(employees, surnames, allNumbers, size));
}

TEST(PrintTest, OutputToFile) {
    std::ofstream file("output.txt");
    Employee employees[3];
    size_t size = 3; 
    ASSERT_NO_THROW(print(file, employees, size)); 
}

TEST(CompTest, CompareEmployees) {
    Employee employee1, employee2;
    employee1.surname = "Strashnov";
    employee1.children = 2;
    employee2.surname = "Rubec";
    employee2.children = 3;
    ASSERT_TRUE(comp(employee1, employee2)); 
}

TEST(SwapStringTest, SwappingEmployees) {
    Employee employees[3];
    size_t size = 3;
    swapString(employees, size);
    ASSERT_EQ(employees[0].surname, "Strashnov");
    ASSERT_EQ(employees[size - 1].surname, "Rubec");
}

TEST(OutputInTxtFileTest, OutputToFile) {
    Employee employees[3]; 
    size_t size = 3; 
    ASSERT_NO_THROW(outputInTxtFile(employees, size));
}

TEST(OutputInBinFileTest, OutputToFile) {
    Employee employees[3]; 
    size_t size = 3; 
    ASSERT_NO_THROW(outputInBinFile(employees, size));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
