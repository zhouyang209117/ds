#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "list/list.h"
typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;


void printStu(void* stu) {
    Student* tmp = (Student*)stu;
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
    printf("%ls:\n", L"删除");
    int result = list->Remove(list, 0, sizeof(Student));
    if (result != 0) {
        printf("delete error\n");
    }
    printf("%ls:\n", L"遍历结果");
    list->Traverse(list, sizeof(Student), printStu);
    int index = list->Find(list, &stu3, sizeof(Student), equal);
    printf("%d\n", index);
    return 0;
}