#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <interface/comparator.h>
#include <list/sq.h>
#include "common.c"

void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    if (tmp == NULL) {
        printf("null pointer error\n");
        return;
    }
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
}

bool equal(void* s1, void* s2) {
    Student* p1 = (Student*)s1;
    Student* p2 = (Student*)s2;
    if (p1->num == p2->num) {
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
    SqList* list = CreateSqList(sizeof(Student), cmp);
    for (int i = 0; i < 20; i++) {
        wchar_t* name = (wchar_t*)malloc(sizeof(wchar_t) * 10);
        swprintf(name, 10, L"%s%d", "张三", i);
        Student* stu = CreateStudent(i, name);
        list->Add(list, 0, (void*)stu);
    }
    printf("next:\n");
    Iterator *ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printStu(ite->Next(ite));
    }
    printf("%ls:\n", L"修改");
    Student stu3;
    stu3.num = 3;
    stu3.name = L"张三3";
    list->Set(list, 1, &stu3);
    printf("%ls:\n", L"删除");
    int result = list->Remove(list, 0);
    if (result != 0) {
        printf("delete error\n");
    }
    int index = list->Find(list, &stu3);
    printf("%d\n", index);
    printf("sort:\n");
    list->Sort(list);
    return 0;
}