#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "list/link.h"
typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;


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

Student* CreateStudent(int num ,wchar_t* name) {
    Student* s = (Student*)malloc(sizeof(Student));
    s->num = num;
    s->name = name;
    return s;
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LinkList* list = CreateLinkList();
    Student* stu1 = CreateStudent(100, L"张三1");
    Student* stu2 = CreateStudent(1, L"张三2");
    Student* stu3 = CreateStudent(90, L"张三3");
    Student* stu4 = CreateStudent(2, L"张三4");
    list->Add(list, 0, stu1, sizeof(Student));
    list->Add(list, 0, stu2, sizeof(Student));
    list->Add(list, 0, stu3, sizeof(Student));
    list->Add(list, 0, stu4, sizeof(Student));
    list->Traverse(list, printStu);
    int result = list->Find(list, stu2, equal);
    printf("found index:%d\n", result);
    printf("get result:\n");
    printStu(list->Get(list, 0));
    printf("sort\n");
    list->Sort(list, sizeof(Student), gt);
    list->Traverse(list, printStu);
    printf("next:\n");
    Iterator *ite = list->CreateIterator(list);
    while (ite->hasNext(ite)) {
        printStu(ite->next(ite));
    }
    return 0;
}