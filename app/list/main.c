#include <stdio.h>
#include "list/list.h"
typedef struct Student_ {
    int num;
    char* name;
}Student;

int main() {
    SqList* list = CreateSqList(10, sizeof(Student));
    Student stu;
    stu.num = 2;
    stu.name = "zhang3";
    list->Add(list, (void*)(&stu), sizeof(Student));
    printf("%d\n", list->length);
    printf("%d\n", list->total);
    printf("%d\n", ((Student*)(list->ele))[0].num);
    printf("%s\n", ((Student*)(list->ele))[0].name);
}