#include <gtest/gtest.h>
#include <list/clink.h>

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

TEST(CreateCLink, EqualsOne) {
    CLList* list = CreateCLList(sizeof(Student));
    EXPECT_EQ(list->length, 0);
    int result = list->Add(list, 0, CreateStudent(1, L"张三"));
    EXPECT_EQ(result, 0);
    Student* s1 = (Student*)(list->head->next->ele);
    EXPECT_EQ(s1->num, 1);
    list->Add(list, list->length, CreateStudent(2, L"张三"));
    s1 = (Student*)(list->head->next->ele);
    EXPECT_EQ(s1->num, 1);
}

TEST(CreateCLLIterator, EqualsOne) {
    CLList* list = CreateCLList(sizeof(Student));
    EXPECT_EQ(list->length, 0);
    int result = list->Add(list, 0, CreateStudent(1, L"张三"));
    EXPECT_EQ(result, 0);
    result = list->Add(list, list->length, CreateStudent(2, L"张三1"));
    EXPECT_EQ(result, 0);
    EXPECT_EQ(list->length, 2);
    CLLIterator* ite = list->CreateIterator(list);
    Student* s1 = (Student*)(ite->Next(ite));
    EXPECT_EQ(s1->num, 1);
    s1 = (Student*)(ite->Next(ite));
    EXPECT_EQ(s1->num, 2);
}