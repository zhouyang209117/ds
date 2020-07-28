#include <gtest/gtest.h>
#include <list/sq.h>

typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

Student* CreateStudent(int num, wchar_t* name) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    stu->name = name;
    return stu;
}

TEST(CreateSqList, EqualsOne) {
    SqList* list = CreateSqList(sizeof(Student));
    EXPECT_EQ(list->length, 0);
}

TEST(SqListAdd, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0, L"张三1");
    Student* stu2 = CreateStudent(0, L"张三2");
    Student* stu3 = CreateStudent(0, L"张三3");
    SqList* list = CreateSqList(sizeof(Student));
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 0, stu2);
    int result3 = list->Add(list, 0, stu3);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(list->length, 3);
}