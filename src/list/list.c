#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list/list.h"

SqList* CreateSqList(int totalLen, int eleSize) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    sqList->total = totalLen;
    sqList->ele = (char*)malloc(totalLen * eleSize);
    sqList->Add = Add;
    sqList->length = 0;
    return sqList;
}

int Add(SqList* self, void* data, int size) {
    if (self->length == self->total) {
        return 1;
    }
    memcpy(self->ele + self->length, data, size);
    self->length += 1;
    return 0;
}