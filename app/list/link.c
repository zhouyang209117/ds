#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <list/link.h>
#include "common.c"

void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
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

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Comparator* cmp = CreateComparator();
    LList* list = CreateLList(sizeof(Student), cmp);
    Student* stu1 = CreateStudent(100, L"张三1");
    Student* stu2 = CreateStudent(1, L"张三2");
    Student* stu3 = CreateStudent(90, L"张三3");
    Student* stu4 = CreateStudent(2, L"张三4");
    list->Add(list, 0, stu1);
    list->Add(list, 0, stu2);
    list->Add(list, 0, stu3);
    list->Add(list, 0, stu4);
    int result = list->Find(list, stu2);
    printf("find index=%d\n", result);
    printf("sort\n");
    list->Sort(list);
    printf("next:\n");
    LLIterator *ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printStu(ite->Next(ite));
    }
    list->Delete(list, stu1);
    printf("deleted:\n");
    ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printStu(ite->Next(ite));
    }
    return 0;
}