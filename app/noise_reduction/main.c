#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include "list/list.h"
typedef struct Node_ {
    int num;
    wchar_t Char;
}Node;


void printNode(void* node) {
    Node* tmp = (Node*)node;
    printf("num=%ls,name=%d\n", tmp->Char, tmp->num);
}

bool equal(void* a, void* b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    if(((Node*)a)->Char == ((Node*)b)->Char) {
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
    int result = list->Remove(list, 2, sizeof(Student));
    if (result != 0) {
        printf("delete error\n");
    }
    printf("%ls:\n", L"遍历结果");
    list->Traverse(list, sizeof(Student), printStu);
    return 0;
}