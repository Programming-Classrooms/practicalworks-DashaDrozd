#include "gtest/gtest.h"
#include "../func/Student2.h"

TEST(StudentTest, ParameterizedConstructor) {
    Student2 student("Alice", 2, 101, 123456);

    EXPECT_EQ(student.getName(), "Alice");
    EXPECT_EQ(student.getCourse(), 2);
    EXPECT_EQ(student.getGroup(), 101);
    EXPECT_EQ(student.getRecordNumber(), 123456);
}

TEST(StudentTest, CopyConstructor) {
    Student2 student1("Alice", 2, 101, 123456);
    Student2 student2(student1);

    EXPECT_EQ(student2.getName(), "Alice");
    EXPECT_EQ(student2.getCourse(), 2);
    EXPECT_EQ(student2.getGroup(), 101);
    EXPECT_EQ(student2.getRecordNumber(), 123456);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
