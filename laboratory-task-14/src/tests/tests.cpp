#include <gtest/gtest.h>
#include "../func/Person.h"
#include "../func/Student.h"
#include <sstream>


// Тест конструктора с параметром
TEST(PersonTest, ParameterizedConstructor) {
    Person p("Dasha Drozd");
    EXPECT_STREQ("Dasha Drozd", p.getFullName());
}

// Тест конструктора копирования
TEST(PersonTest, CopyConstructor) {
    Person p1("Dasha Drozd");
    Person p2(p1);
    EXPECT_STREQ("Dasha Drozd", p2.getFullName());
}

// Тест сеттера и геттера
TEST(PersonTest, SetAndGetFullName) {
    Person p;
    p.setFullName("Dasha Drozd");
    EXPECT_STREQ("Dasha Drozd", p.getFullName());
}

// Тест конструктора по умолчанию
TEST(StudentTest, DefaultConstructor) {
    Student s;
    EXPECT_STREQ("", s.getFullName());
    EXPECT_EQ(1, s.getCourse());
    EXPECT_EQ(1, s.getGroup());
}

// Тест конструктора с параметрами
TEST(StudentTest, ParameterizedConstructor) {
    Student s("John Doe", 3, 2);
    EXPECT_STREQ("John Doe", s.getFullName());
    EXPECT_EQ(3, s.getCourse());
    EXPECT_EQ(2, s.getGroup());
}

// Тест геттеров и сеттеров
TEST(StudentTest, GetterAndSetter) {
    Student s;
    s.setFullName("Jane Doe");
    s.setCourse(2);
    s.setGroup(4);
    EXPECT_STREQ("Jane Doe", s.getFullName());
    EXPECT_EQ(2, s.getCourse());
    EXPECT_EQ(4, s.getGroup());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
