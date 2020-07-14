#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "linklist/linklist.h"
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
    result = list->Find(list, &stu2, equal);
    printf("found index:%d\n", result);
    printf("get result:\n");
    printStu(list->Get(list, 0));
    return 0;
}