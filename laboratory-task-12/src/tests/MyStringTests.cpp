#include<gtest/gtest.h>
#include "../MyString/MyString.hpp"


TEST(MyStringTest, ConstructorWithStringParameter)
{
	const char* testStr = "Hello";
	MyString str(testStr);
	EXPECT_EQ(str.getSize(), std::strlen(testStr));
}

TEST(MyStringTest, DefaultConstructor)
{
	MyString str;
	EXPECT_EQ(str.getSize(), 0);
}

TEST(MyStringTest, AssignmentOperator)
{
	const char* testStr1 = "Hello";
	const char* testStr2 = "World";
	MyString str1(testStr1);
	MyString str2;
	str2 = str1;
	EXPECT_EQ(str1.getSize(), str2.getSize());
	EXPECT_EQ(str1, str2);
}

TEST(MyStringTest, AddOperator)
{
	const char* testStr1 = "Hello";
	const char* testStr2 = "World";
	MyString str1(testStr1);
	MyString str2(testStr2);
	MyString concatenatedStr = str1 + str2;
	EXPECT_EQ(concatenatedStr.getSize(), str1.getSize() + str2.getSize());
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
