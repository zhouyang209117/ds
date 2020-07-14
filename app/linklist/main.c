#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "linklist/linklist.h"
typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;


void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LinkList* list = CreateLinkList();
    Student stu1;
    stu1.name = L"张三1";
    stu1.num = 1;
    Student stu2;
    stu2.name = L"张三2";
    stu2.num = 2;
    int result = list->Add(list, 0, &stu1, sizeof(Student));
    if (result != 0) {
        printf("add error\n");
        return 1;
    }
    result = list->Add(list, 1, &stu2, sizeof(Student));
    if (result != 0) {
        printf("add error\n");
        return 1;
    }
    list->Traverse(list, printStu);
    return 0;
}