#include <gtest/gtest.h>
#include <list/clink.h>
#include <interface/comparator.h>

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

TEST(CLListTest, EqualsOne) {
    CLList* list = CreateCLList(sizeof(Student), CreateComparator());
    EXPECT_EQ(list->length, 0);
    Student* stu1 = CreateStudent(1, L"张三1");
    Student* stu2 = CreateStudent(2, L"张三2");
    Student* stu3 = CreateStudent(3, L"张三3");
    Student* stu4 = CreateStudent(4, L"张三4");
    int result1 = list->Add(list, 0, stu1);
    int result2 = list->Add(list, 1, stu2);
    int result3 = list->Add(list, 1, stu3);
    int result4 = list->Add(list, 2, stu4);
    EXPECT_EQ(list->length, 4);
    EXPECT_EQ(result1, 0);
    EXPECT_EQ(result2, 0);
    EXPECT_EQ(result3, 0);
    EXPECT_EQ(result4, 0);
    int a[4] = {1, 3, 4, 2};
    CLLIterator* ite = list->CreateIterator(list);
    for (int i = 0; i < 4; i++) {
        if (ite->HasNext(ite)) {
            Student* s1 = (Student*)(ite->Next(ite));
            EXPECT_EQ(s1->num, a[i]);
        }
    }
    int result5 = list->Find(list, stu1);
    int result6 = list->Find(list, stu2);
    EXPECT_EQ(result5, 0);
    EXPECT_EQ(result6, 3);
    Student* stu00 = (Student*)list->Get(list, 0);
    EXPECT_EQ(stu00->num, 1);
    stu00 = (Student*)list->Get(list, 3);
    EXPECT_EQ(stu00->num, 2);
}