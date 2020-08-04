#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list/clink.h"
#include "code/code.h"

static int Add(CLList*, int, void*);
static int Delete(CLList*, void*, bool(*eq)(void*, void*));
static CLLIterator* CreateIterator(CLList*);

CLList* CreateCLList(int dataSize) {
    if (dataSize == 0) {
        return NULL;
    }
    CLLNode* head = (CLLNode*)malloc(sizeof(CLLNode));
    if (head == NULL) {
        return ENOMEM;
    }
    head->ele = NULL;
    head->next = head;
    CLList* list = (CLList*)malloc(sizeof(CLList));
    if (list == NULL) {
        return ENOMEM;
    }
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = Add;
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

static int Delete(CLList* self, void* data, bool(*eq)(void*, void*)) {
    if (self == NULL) {
        return EAGAIN;
    }
    CLLNode* current = self->head;
    while (current->next != self->head) {
        if (eq(current->next->ele, data)) {
            CLLNode* tmp = current->next;
            current->next = current->next->next;
            self->length -= 1;
            free(tmp);
            return 0;
        }
        current = current->next;
    }
    return ENOTFOUND;
}