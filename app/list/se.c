#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "list/se.h"
typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;


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

Student* CreateStudent(int num, wchar_t* name) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    stu->name = name;
    return stu;
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(sizeof(Student));
    for (int i = 0; i < 20; i++) {
        wchar_t* name = (wchar_t*)malloc(sizeof(wchar_t) * 10);
        swprintf(name, 10, L"%s%d", "张三", i);
        Student* stu = CreateStudent(i, name);
        list->Add(list, 0, (void*)stu, sizeof(Student));
    }
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