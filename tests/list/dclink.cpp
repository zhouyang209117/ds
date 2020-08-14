#include <gtest/gtest.h>
#include <list/dclink.h>
#include "../common.c"


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

TEST(DCLLIterator, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(1);
    Student* stu2 = CreateStudent(2);
    Student* stu3 = CreateStudent(3);
    Student* stu4 = CreateStudent(4);
    Student* stu5 = CreateStudent(5);
    DCLList* list = CreateDCLList(sizeof(Student), CreateComparator());
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 1, stu2);
    int result3 = list->Add(list, 0, stu3);
    int result4 = list->Add(list, 3, stu4);
    int result5 = list->Add(list, 2, stu5);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(result4, 0);
    EXPECT_EQ(result5, 0);
    EXPECT_EQ(list->length, 5);
    int a[5] = {3, 1, 5, 2, 4};
    DCLLIterator* ite = list->CreateIterator(list);
    int i = 0;
    while (ite->HasNext(ite)) {
        Student* stu = (Student*)ite->Next(ite);
        EXPECT_EQ(stu->num, a[i]);
        i++;
    }
    int result00 = list->Delete(list, stu3);
    EXPECT_EQ(result00, 0);
    int b[4] = {1, 5, 2, 4};
    ite = list->CreateIterator(list);
    i = 0;
    while (ite->HasNext(ite)) {
        Student* stu = (Student*)ite->Next(ite);
        EXPECT_EQ(stu->num, b[i]);
        i++;
    }
    int result01 = list->Delete(list, stu4);
    EXPECT_EQ(result01, 0);
    int c[3] = {1, 5, 2};
    ite = list->CreateIterator(list);
    i = 0;
    while (ite->HasNext(ite)) {
        Student* stu = (Student*)ite->Next(ite);
        EXPECT_EQ(stu->num, c[i]);
        i++;
    }
    EXPECT_EQ(list->length, 3);
    int result02 = list->Find(list, stu1);
    EXPECT_EQ(result02, 0);
    int result03 = list->Find(list, stu2);
    EXPECT_EQ(result03, 2);
    Student* s00 = (Student*)list->Get(list, 0);
    EXPECT_EQ(s00->num, 1);
    Student* s01 = (Student*)list->Get(list, 2);
    EXPECT_EQ(s01->num, 2);
}