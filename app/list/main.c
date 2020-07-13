#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "list/list.h"
typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(10, sizeof(Student));
    Student stu1;
    stu1.num = 1;
    stu1.name = L"张三1";
    Student stu2;
    stu2.num = 2;
    stu2.name = L"张三2";
    printf("%lu\n", sizeof(Student));
    list->Add(list, (void*)(&stu1), sizeof(Student));
    list->Add(list, (void*)(&stu2), sizeof(Student));

    void* stuSrc = list->Get(list, 0, sizeof(Student));
    Student stuDest;
    memcpy(&stuDest, stuSrc, sizeof(Student));
    printf("num=%d,name=%ls\n", stuDest.num, stuDest.name);
    return 0;
}