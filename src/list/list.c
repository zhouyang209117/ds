#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

SqList* CreateSqList(int total) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    sqList->total = total;
    sqList->ele = (int*)malloc(sizeof(int) * total);
    sqList->Add = Add;
    sqList->length = 0;
    return sqList;
}

int Add(SqList* self, int a) {
    if (self->length == self->total) {
        return 1;
    }
    *(self->ele + self->length) = a;
    self->length += 1;
    return 0;
}