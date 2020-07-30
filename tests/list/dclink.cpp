#include <gtest/gtest.h>
#include <list/dclink.h>

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

TEST(CreateDCLinkList, EqualsOne) {
    DCLList* list = CreateDCLList(sizeof(Student));
    EXPECT_EQ(true, list != NULL);
    EXPECT_EQ(list->length, 0);
}

TEST(DCLinkListAdd, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0, L"张三1");
    Student* stu2 = CreateStudent(0, L"张三2");
    Student* stu3 = CreateStudent(0, L"张三3");
    DCLList* list = CreateDCLList(sizeof(Student));
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 0, stu2);
    int result3 = list->Add(list, 0, stu3);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(list->length, 3);
}

TEST(DCLLIterator, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0, L"张三1");
    Student* stu2 = CreateStudent(1, L"张三2");
    Student* stu3 = CreateStudent(2, L"张三3");
    DCLList* list = CreateDCLList(sizeof(Student));
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 0, stu2);
    int result3 = list->Add(list, 0, stu3);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(list->length, 3);
    DCLLIterator* ite = list->CreateIterator(list);
    Student* stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 2);
    stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 1);
    stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 0);
}