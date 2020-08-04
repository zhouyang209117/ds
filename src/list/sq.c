#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <interface/comparator.h>
#include <list/sq.h>

static int       Add           (SqList*, int, void*);
static void*     Get           (SqList*, int);
static int       Set           (SqList*, int, void*);
static int       Remove        (SqList*, int);
static int       Find          (SqList*, void*);
static void      Sort          (SqList*);
static Iterator* CreateIterator(SqList*);

SqList* CreateSqList(int eleSize, Comparator* comparator) {
    SqList* sqList = (SqList*)malloc(sizeof(SqList));
    if (sqList == NULL) {
        return NULL;
    }
    sqList->total = SE_LIST_INIT_SIZE;
    sqList->ele = (char*)malloc(eleSize * SE_LIST_INIT_SIZE);
    sqList->length = 0;
    sqList->dataSize = eleSize;
    sqList->comparator = comparator;
    sqList->Add = Add;
    sqList->Get = Get;
    sqList->Set = Set;
    sqList->Remove = Remove;
    sqList->Find = Find;
    sqList->Sort = Sort;
    sqList->CreateIterator = CreateIterator;
    return sqList;
}

static int Add(SqList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    if (self->length == self->total) {
        self->ele = (char*)realloc(self->ele, (self->length * 2) * self->dataSize);
        self->total = self->length * 2;
    }
    for (int i = self->length - 1; i >= index; i--) {
        memcpy(self->ele + (i + 1) * self->dataSize,
               self->ele + i * self->dataSize, self->dataSize);
    }
    if (data != NULL) {
        memcpy(self->ele + index * self->dataSize, data, self->dataSize);
    }
    self->length += 1;
    return 0;
}

static void* Get(SqList* self, int index) {
    if (index >= self->length) {
        return NULL;
    }
    return self->ele + index * self->dataSize;
}

static int Set(SqList* self, int index, void* data) {
    if (index >= self->length) {
        return 1;
    }
    int offset = index * self->dataSize;
    memcpy(self->ele + offset, data, self->dataSize);
    return 0;
}

static int Remove(SqList* self, int index) {
    if (index < 0 || index >= self->length) {
        return 1;
    }
    for (int i = index; i < self->length - 1; i++) {
        int offset1 = i * self->dataSize;
        int offset2 = (i + 1) * self->dataSize;
        memcpy(self->ele + offset1, self->ele + offset2, self->dataSize);
    }
    self->length -= 1;
    if (self->length * 2 < self->total && self->total > SE_LIST_INIT_SIZE) {
        self->ele = (char*)realloc(self->ele, (self->total / 2) * self->dataSize);
        self->total = self->total / 2;
    }
    return 0;
}

static int Find(SqList* self, void* data) {
    for (int i = 0; i < self->length; i++) {
        char* current = self->ele + self->dataSize * i;
        printf("%p\n", self->comparator);
        if (self->comparator->Equal(data, current)) {
            return i;
        }
    }
    return -1;
}

static void swap(void* a, void* b, int size) {
    char* tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

static void Sort(SqList* self) {
    for (int i = self->length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (self->comparator->CompareTo(self->ele + j * self->dataSize,
                                            self->ele + (j + 1) * self->dataSize)) {
                swap(self->ele + j * self->dataSize,
                     self->ele + (j + 1) * self->dataSize, self->dataSize);
            }
        }
    }
}

static void* Next(Iterator* self) {
    void* data = self->ele + (self->index * self->dataSize);
    self->index++;
    return data;
}

static bool HasNext(Iterator* self) {
    return self->index <= self->length - 1;
}

Iterator* CreateIterator(SqList* self) {
    Iterator* ite = (Iterator*)malloc(sizeof(Iterator));
    if (ite == NULL) {
        return NULL;
    }
    ite->length = self->length;
    ite->dataSize = self->dataSize;
    ite->index = 0;
    ite->ele = self->ele;
    ite->HasNext = HasNext;
    ite->Next = Next;
    return ite;
}