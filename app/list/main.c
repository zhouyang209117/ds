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


void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(10, sizeof(Student));
    Student stu1;
    stu1.num = 1;
    stu1.name = L"张三1";
    Student stu2;
    stu2.num = 2;
    stu2.name = L"张三2";
    list->Add(list, (void*)(&stu1), sizeof(Student));
    list->Add(list, (void*)(&stu2), sizeof(Student));
    Student* stuSrc = list->Get(list, 0, sizeof(Student));
    printf("num=%d,name=%ls\n", stuSrc->num, stuSrc->name);
    printf("%ls:\n", L"遍历结果");
    list->Traverse(list, sizeof(Student), printStu);
    printf("%ls:\n", L"修改");
    Student stu3;
    stu3.num = 3;
    stu3.name = L"张三3";
    list->Set(list, 1, sizeof(Student), &stu3);
    printf("%ls:\n", L"遍历结果");
    list->Traverse(list, sizeof(Student), printStu);
    return 0;
}