#include <gtest/gtest.h>
#include <list/sq.h>
#include "../common.c"

TEST(CreateSqList, EqualsOne) {
    SqList* list = CreateSqList(sizeof(Student), NULL);
    EXPECT_EQ(list->length, 0);
}

TEST(SqListAdd, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0);
    Student* stu2 = CreateStudent(1);
    Student* stu3 = CreateStudent(2);
    SqList* list = CreateSqList(sizeof(Student), NULL);
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 0, stu2);
    int result3 = list->Add(list, 0, stu3);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(list->length, 3);
}