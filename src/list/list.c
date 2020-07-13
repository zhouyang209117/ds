#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list/list.h"

SqList* CreateSqList(int totalLen, int eleSize) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    sqList->total = totalLen;
    sqList->ele = (char*)malloc(totalLen * eleSize);
    sqList->length = 0;

    sqList->Add = Add;
    sqList->Get = Get;
    sqList->Set = Set;
    sqList->Traverse = Traverse;
    return sqList;
}

int Add(SqList* self, void* data, int size) {
    if (self->length == self->total) {
        return 1;
    }
    int offset = self->length * size;
    memcpy(self->ele + offset, data, size);
    self->length += 1;
    return 0;
}

void* Get(SqList* self, int index, int size) {
    if (index >= self->length) {
        return NULL;
    }
    return self->ele + (self->length - 1) * size;
}

int Set(SqList* self, int index, int size, void* data) {
    if (index >= self->length) {
        return 1;
    }
    int offset = index * size;
    memcpy(self->ele + offset, data, size);
    return 0;
}

void Traverse(SqList* self, int size, void(*traverse)(void*)) {
    for (int i = 0; i < self->length; i++) {
        char* current = self->ele + size * i;
        traverse((void*)current);
    }
}