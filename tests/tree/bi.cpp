#include <gtest/gtest.h>
#include <list/sq.h>
#include <tree/bi.h>
#include <stdlib.h>

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

bool empty(void* data) {
    return ((Student*)data)->num == -1;
}

TEST(BiTree, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0, L"张三1");
    Student* stu2 = CreateStudent(-1, L"张三1");
    Student* stu3 = CreateStudent(-1, L"张三1");
    SqList* list = CreateSqList(sizeof(Student));
    int result1 = list->Add(list, list->length, stu1);
    int result2 = list->Add(list, list->length, stu2);
    int result3 = list->Add(list, list->length, stu3);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(list->length, 3);
    BiTree* tree = CreateBiTree(list, empty);
    EXPECT_EQ(true, tree != NULL);
}