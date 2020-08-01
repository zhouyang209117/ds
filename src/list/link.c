#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include "list/link.h"

void swap(void* a, void* b, int size) {
    char* tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

LList* LL_Create(int dataSize) {
    LLNode* head = (LLNode*)malloc(sizeof(LLNode));
    head->ele = NULL;
    head->next = NULL;
    LList* list = (LList*)malloc(sizeof(LList));
    if (list == NULL) {
        return NULL;
    }
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = LL_Add;
    list->Push = LL_Push;
    list->Pop = LL_Pop;
    list->Empty = LL_Empty;
    list->Find = LL_Find;
    list->Sort = LL_Sort;
    list->CreateIterator = LL_CreateIterator;
    list->Delete = LL_Delete;
    return list;
}

int LL_Add(LList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    LLNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    char* newData = (char*)malloc(self->dataSize);
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    newNode->next = tmp->next;
    tmp->next = newNode;
    self->length += 1;
    return 0;
}

int LL_Push(LList* self, void* data) {
    return LL_Add(self, 0, data);
}

int LL_Pop(LList* self) {
    if (self->head->next == NULL) {
        return ENOTFOUND;
    }
    LLNode* tmp = self->head->next;
    self->head->next = self->head->next->next;
    self->length -= 1;
    free(tmp);
    return 0;
}

bool LL_Empty(LList* self) {
    return self->length == 0;
}

void* LL_Find(LList* self, void* data, bool(*equal)(void*, void*)) {
    LLNode* tmp = self->head->next;
    while (tmp != NULL) {
        if (equal(tmp->ele, data)) {
            return tmp->ele;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int LL_Delete(LList* self, void* data, bool(*eq)(void*, void*)) {
    LLNode* current = self->head;
    while (current->next != NULL) {
        if (eq(current->next->ele, data)) {
            LLNode* tmp = current->next;
            current->next = tmp->next;
            free(tmp);
            self->length -= 1;
            return 0;
        }
        current = current->next;
    }
    return ENOTFOUND;
}

void* Next(LLIterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

bool HasNext(LLIterator* self) {
    return self->current != NULL;
}

void LL_Sort(LList* self, bool(*gt)(void*, void*)) {
    LLNode* first = self->head->next;
    for (int i = self->length - 1 ; i > 0; i--) {
        LLNode* p1 = first;
        for (int j = 0; j < i; j++) {
            if (gt(p1->ele, p1->next->ele)) {
                swap(p1->ele, p1->next->ele, self->dataSize);
            }
            p1 = p1->next;
        }
    }
}

LLIterator* LL_CreateIterator(LList* self) {
    LLIterator* ite = (LLIterator*)malloc(sizeof(LLIterator));
    ite->current = self->head->next;
    ite->Next = Next;
    ite->HasNext = HasNext;
    return ite;
}