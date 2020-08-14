#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <list/dclink.h>
#include "common.c"

void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    Student* stu1 = CreateStudent(0, L"张三1");
    Student* stu2 = CreateStudent(1, L"张三2");
    Student* stu3 = CreateStudent(2, L"张三3");
    DCLList* list = CreateDCLList(sizeof(Student), NULL);
    list->Add(list, 0, stu1);
    list->Add(list, 0, stu2);
    list->Add(list, 0, stu3);
    DCLLIterator *ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printStu(ite->Next(ite));
    }
    return 0;
}