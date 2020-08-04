#include <list/sq.h>
#include <tree/bi.h>
#include <list/link.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>

typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

Student* CreateStudent(int num, wchar_t* name) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    stu->name = name;
    return stu;
}

bool empty(void* data) {
    return ((Student*)data)->num == -1;
}

void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    if (tmp == NULL) {
        printf("bi.c null pointer error\n");
        return;
    }
    printf("num=%d,name=%ls\n", tmp->num, tmp->name);
}

void simpleTra(BiNode* t) {
    if (t != NULL) {
        simpleTra(t->l);
        printStu(t->data);
        simpleTra(t->r);
    }
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(sizeof(Student), NULL);
    list->Add(list, list->length, CreateStudent(0, L"A"));
    list->Add(list, list->length, CreateStudent(0, L"B"));
    list->Add(list, list->length, CreateStudent(0, L"C"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(0, L"D"));
    list->Add(list, list->length, CreateStudent(0, L"E"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(0, L"G"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(0, L"F"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    list->Add(list, list->length, CreateStudent(-1, L"#"));
    BiTree* tree = CreateBiTree(list, empty);
    BITIterator* iterator = tree->CreateBITIterator(tree);
    if (iterator == NULL) {
        return 1;
    }
    while (iterator->HasNext(iterator)) {
        Student* stu = (Student*)(iterator->Next(iterator));
        printStu(stu);
    }
    simpleTra(tree->head);
    return 0;
}
