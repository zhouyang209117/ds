#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list/list.h"

SqList* CreateSqList(int totalLen, int eleSize) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    sqList->total = totalLen;
    sqList->ele = (char*)malloc(totalLen * eleSize);
    sqList->length = 0;

    sqList->Add = Add;
    sqList->Get = Get;
    sqList->Set = Set;
    sqList->Remove = Remove;
    sqList->Find = Find;
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

int Remove(SqList* self, int index, int size) {
    if (index < 0 || index >= self->length) {
        return 1;
    }
    for (int i = index; i < self->length - 1; i++) {
        int offset1 = i * size;
        int offset2 = (i + 1) * size;
        memcpy(self->ele + offset1, self->ele + offset2, size);
    }
    self->length -= 1;
    return 0;
}

int Find(SqList* self, void* data, int size, bool(*equal)(void*, void*)) {
    for (int i = 0; i < self->length; i++) {
        char* current = self->ele + size * i;
        if (equal(data, current)) {
            return i;
        }
    }
    return -1;
}

void Traverse(SqList* self, int size, void(*traverse)(void*)) {
    for (int i = 0; i < self->length; i++) {
        char* current = self->ele + size * i;
        traverse((void*)current);
    }
}