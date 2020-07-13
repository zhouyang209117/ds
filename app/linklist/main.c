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
    LinkList* list = CreateLinkList();
    return 0;
}