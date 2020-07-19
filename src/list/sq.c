#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list/sq.h"

SqList* CreateSqList(int eleSize) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    sqList->total = SE_LIST_INIT_SIZE;
    sqList->ele = (char*)malloc(eleSize * SE_LIST_INIT_SIZE);
    sqList->length = 0;

    sqList->Add = Add;
    sqList->Get = Get;
    sqList->Set = Set;
    sqList->Remove = Remove;
    sqList->Find = Find;
    sqList->Sort = Sort;
    sqList->Traverse = Traverse;
    sqList->CreateIterator = CreateIterator;
    return sqList;
}

int Add(SqList* self, int index, void* data, int size) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    if (self->length == self->total) {
        self->ele = (char*)realloc(self->ele, (self->length * 2) * size);
        self->total = self->length * 2;
    }
    for (int i = self->length - 1; i >= index; i--) {
        memcpy(self->ele + (i + 1) * size, self->ele + i * size, size);
    }
    memcpy(self->ele + index * size, data, size);
    self->length += 1;
    return 0;
}

void* Get(SqList* self, int index, int size) {
    if (index >= self->length) {
        return NULL;
    }
    return self->ele + index * size;
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
    if (self->length * 2 < self->total && self->total > SE_LIST_INIT_SIZE) {
        self->ele = (char*)realloc(self->ele, (self->total / 2) * size);
        self->total = self->total / 2;
    }
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

void swap(void* a, void* b, int size) {
    char* tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

void Sort(SqList* self, int size, bool(*gt)(void*, void*)) {
    for (int i = self->length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (gt(self->ele + j * size, self->ele + (j + 1) * size)) {
                swap(self->ele + j * size, self->ele + (j + 1) * size, size);
            }
        }
    }
}

void* Next(Iterator* self, int size) {
    void* data = self->ele + (self->index * size);
    self->index++;
    return data;
}

bool HasNext(Iterator* self) {
    return self->index <= self->length - 1;
}

Iterator* CreateIterator(SqList* self) {
    Iterator* ite = (Iterator*)malloc(sizeof(Iterator));
    ite->length = self->length;
    ite->index = 0;
    ite->ele = self->ele;
    ite->hasNext = HasNext;
    ite->next = Next;
    return ite;
}