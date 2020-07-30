#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include "list/dclink.h"


DCLList* CreateDCLList(int dataSize) {
    DCLNode* head = (DCLNode*)malloc(sizeof(DCLNode));
    if (head == NULL) {
        return NULL;
    }
    head->ele = NULL;
    head->next = head;
    head->pre = head;
    DCLList* list = (DCLList*)malloc(sizeof(DCLList));
    if (list == NULL) {
        return NULL;
    }
    list->dataSize = dataSize;
    list->head = head;
    list->Add = Add;
    list->CreateIterator = CreateDCLLIterator;
    list->length = 0;
    return list;
}

int add(DCLList* self, int index, void* data) {
    DCLNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    DCLNode* newNode = (DCLNode*)malloc(sizeof(DCLNode));
    if (newNode == NULL) {
        return ENOMEM;
    }
    char* newData = (char*)malloc(self->dataSize);
    if (newData == NULL) {
        return ENOMEM;
    }
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    tmp->next->pre = newNode;
    newNode->next = tmp->next;
    newNode->pre = tmp;
    tmp->next = newNode;
    self->length += 1;
}

int Add(DCLList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return EAGAIN;
    }
    if (self->length == 0) {
        add(self, 0, data);
    } else {
        add(self, index % self->length, data);
    }
    return 0;
}

void* Next(DCLLIterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

bool HasNext(DCLLIterator* self) {
    return self->current != self->head;
}

DCLLIterator* CreateDCLLIterator(DCLList* list) {
    DCLLIterator* ite = (DCLLIterator*)malloc(sizeof(DCLLIterator));
    if (ite == NULL) {
        return NULL;
    }
    ite->current = list->head->next;
    ite->head = list->head;
    ite->Next = Next;
    ite->HasNext = HasNext;
    return ite;
}