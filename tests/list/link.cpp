#include <gtest/gtest.h>
#include <list/link.h>
#include <locale.h>
#include <code/code.h>


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

bool equal(void* stu1, void* stu2) {
    if (((Student*)stu1)->num == ((Student*)stu2)->num) {
        return true;
    } else {
        return false;
    }
}

bool gt(void* a1, void* a2) {
    Student* s1 = (Student*)a1;
    Student* s2 = (Student*)a2;
    if (s1->num > s2->num) {
        return true;
    } else {
        return false;
    }
}

Comparator* CreateComparator() {
    Comparator* cmp = (Comparator*)malloc(sizeof(Comparator));
    if (cmp == NULL) {
        return NULL;
    }
    cmp->CompareTo = gt;
    cmp->Equal = equal;
    return cmp;
}

TEST(LListTest, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(1, L"张三1");
    Student* stu2 = CreateStudent(2, L"张三2");
    Student* stu3 = CreateStudent(3, L"张三3");
    Student* stu4 = CreateStudent(4, L"张三3");
    Student* stu5 = CreateStudent(5, L"张三3");
    LList* list = CreateLList(sizeof(Student), CreateComparator());
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 0, stu2);
    int result3 = list->Add(list, 0, stu3);
    int result4 = list->Add(list, 3, stu4);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(result4, 0);
    EXPECT_EQ(list->length, 4);
    LLIterator* ite = list->CreateIterator(list);
    Student* stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 3);
    stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 2);
    stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 1);
    stu = (Student*)ite->Next(ite);
    EXPECT_EQ(stu->num, 4);
    int result = list->Find(list, stu4);
    EXPECT_EQ(result, 3);
    result = list->Find(list, stu3);
    EXPECT_EQ(result, 0);
    Student* a = (Student*)(list->Get(list, 0));
    EXPECT_EQ(a->num, 3);
    a = (Student*)(list->Get(list, 3));
    EXPECT_EQ(a->num, 4);
    result = list->Delete(list, stu3);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(list->length, 3);
    result = list->Delete(list, stu4);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(list->length, 2);
    result = list->Delete(list, stu5);
    EXPECT_EQ(result, ENOTFOUND);
    EXPECT_EQ(list->length, 2);
}