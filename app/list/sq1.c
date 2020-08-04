#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <interface/comparator.h>
#include <list/sq.h>

bool equal(void* s1, void* s2) {
    int* p1 = (int*)s1;
    int* p2 = (int*)s2;
    return *p1 == *p2;
}

bool gt(void* a1, void* a2) {
    int* p1 = (int*)a1;
    int* p2 = (int*)a2;
    return *p1 > *p2;
}

Comparator* CreateComparator() {
    Comparator* cmp = (Comparator*)malloc(sizeof(Comparator));
    if (cmp == NULL) {
        return NULL;
    }
    cmp->CompareTo = gt;
    cmp->Equal = equal;
    return cmp;
}

int main() {
    Comparator* cmp = CreateComparator();
    SqList* list = CreateSqList(sizeof(int), cmp);
    int a0 = -1;
    int a1 = 10;
    int a2 = 1;
    int a3 = 2;
    int a4 = 3;
    int a5 = 9;
    int a6 = 19;
    list->Add(list, 0, (void*)(&a0));
    list->Add(list, 0, (void*)(&a1));
    list->Add(list, 1, (void*)(&a2));
    list->Add(list, 2, (void*)(&a3));
    list->Add(list, 0, (void*)(&a4));
    list->Add(list, 3, (void*)(&a5));
    list->Add(list, 1, (void*)(&a6));
    printf("next:\n");
    Iterator *ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printf("%d\n", *((int*)(ite->Next(ite))));
    }
    int a7 = 12;
    printf("modify\n");
    list->Set(list, 1, &a7);
    ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printf("%d\n", *((int*)(ite->Next(ite))));
    }
    printf("delete\n");
    int result = list->Remove(list, 0);
    if (result != 0) {
        printf("delete error\n");
    }
    ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printf("%d\n", *((int*)(ite->Next(ite))));
    }
    int index = list->Find(list, &a7);
    printf("%d\n", index);
    printf("sort:\n");
    list->Sort(list);
    ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        printf("%d\n", *((int*)(ite->Next(ite))));
    }
    return 0;
}