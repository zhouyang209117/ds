#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <interface/comparator.h>
#include "list/clink.h"
#include "code/code.h"

static int   Add   (CLList*, int, void*);
static int   Find  (CLList*, void*);
static void* Get   (CLList*, int);
static int   Delete(CLList*, void*);

static CLLIterator* CreateIterator(CLList*);

CLList* CreateCLList(int dataSize, Comparator* cmp) {
    if (dataSize == 0) {
        return NULL;
    }
    CLLNode* head = (CLLNode*)malloc(sizeof(CLLNode));
    if (head == NULL) {
        return NULL;
    }
    head->ele = NULL;
    head->next = head;
    CLList* list = (CLList*)malloc(sizeof(CLList));
    if (list == NULL) {
        return NULL;
    }
    list->comparator = cmp;
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = Add;
    list->Find = Find;
    list->Get = Get;
    list->Delete = Delete;
    list->CreateIterator = CreateIterator;
    return list;
}

static int Add(CLList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return EAGAIN;
    }
    CLLNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    CLLNode* newNode = (CLLNode*)malloc(sizeof(CLLNode));
    if (newNode == NULL) {
        return ENOMEM;
    }
    char* newData = (char*)malloc(self->dataSize);
    if (newData == NULL) {
        return ENOMEM;
    }
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    newNode->next = tmp->next;
    tmp->next = newNode;
    self->length += 1;
    return 0;
}

static void* Next(CLLIterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

static bool HasNext(CLLIterator* self) {
    return self->current != self->head;
}

static CLLIterator* CreateIterator(CLList* self) {
    CLLIterator* ite = (CLLIterator*)malloc(sizeof(CLLIterator));
    if (ite == NULL) {
        return NULL;
    }
    ite->head = self->head;
    ite->current = self->head->next;
    ite->Next = Next;
    ite->HasNext = HasNext;
    return ite;
}

static int Find(CLList* self, void* data) {
    if (self == NULL) {
        return -1;
    }
    if (self->head == NULL) {
        return -1;
    }
    CLLNode* current = self->head->next;
    for (int i = 0; current != self->head; i++, current = current->next) {
        if (self->comparator->Equal(current->ele, data)) {
            return i;
        }
    }
    return -2;
}

static void* Get(CLList* self, int index) {
    if (self == NULL) {
        return NULL;
    }
    if (self->head == NULL) {
        return NULL;
    }
    if (index >= self->length) {
        return NULL;
    }
    if (index < 0) {
        return NULL;
    }
    CLLNode* current = self->head->next;
    for (int i = 0; i < index; i++, current = current->next) {
    }
    return current ? current->ele : NULL;
}

static int Delete(CLList* self, void* data) {
    if (self == NULL) {
        return EAGAIN;
    }
    if (self->head == NULL) {
        return EAGAIN;
    }
    int i = 0;
    for (CLLNode* current = self->head; current != self->head || i == 0;
            current = current->next, i++) {
        if (self->comparator->Equal(current->next->ele, data)) {
            CLLNode* tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            return 0;
        }
    }
    return ENOTFOUND;
}