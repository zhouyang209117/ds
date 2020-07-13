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
    Student stu;
    stu.num = 2;
    stu.name = L"中";
    list->Add(list, (void*)(&stu), sizeof(Student));
    void* stuSrc = list->Get(list, 0);
    Student stuDest;
    memcpy(&stuDest, stuSrc, sizeof(Student));
    printf("%d\n", stuDest.num);
    printf("%ls", stuDest.name);
    return 0;
}