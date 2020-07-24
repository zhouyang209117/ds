#include <stdio.h>
#include <stdlib.h>
#include <code/code.h>

typedef struct SqList_ {
    int* ele;
    int total;
    int length;
}SqList;

SqList* CreateSqList(int total) {
    SqList* list = (SqList*)malloc(sizeof(SqList));
    if (list == NULL) {
        return NULL;
    }
    list->length = 0;
    list->total = total;
    list->ele = (int*)malloc(sizeof(int) * total);
    return list;
}

int Add(SqList* list, int index, int data) {
    if (list->length == list->total) {
        return EAGAIN;
    }
    if (index < 0 || index > list->length) {
        return EAGAIN;
    }
    int i = list->length;
    for (; i > index; i--) {
        *(list->ele + i) = *(list->ele + i - 1);
    }
    *(list->ele + i) = data;
    list->length++;
    return 0;
}

int Get(SqList* list, int data) {
    for (int i = 0; i < list->length; i++) {
        if (*(list->ele + i) == data) {
            return i;
        }
    }
    return ENOTFOUND;
}

int Delete(SqList* list, int index) {
    if (index < 0 || index >= list->length) {
        return ENOENT;
    }
    for (int i = index + 1; i < list->length; i++) {
        *(list->ele + i - 1) = *(list->ele + i);
    }
    list->length--;
    return 0;
}

int main() {
    SqList* list = CreateSqList(100);
    Add(list, 0, 11);
    Add(list, 0, 12);
    Add(list, 0, 13);
    Add(list, 0, 14);
    Add(list, 0, 15);
    Add(list, 1, 16);
    for (int i = 0; i < list->length; i++) {
        printf("%d\n", *(list->ele + i));
    }
    int index = Get(list, 16);
    int result = Delete(list, index);
    if (result != 0) {
        printf("delete error\n");
    }
    printf("after delete\n");
    for (int i = 0; i < list->length; i++) {
        printf("%d\n", *(list->ele + i));
    }
    return 0;
}