#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include "list/link.h"

static int         Add           (struct LList_*, int, void*);
static int         Push          (struct LList_*, void*);
static void*       Pop           (struct LList_*);
static bool        Empty         (struct LList_*);
static void*       Find          (struct LList_*, void*, bool(*)(void*, void*));
static void        Sort          (struct LList_*, bool(*)(void*, void*));
static int         Delete        (struct LList_*, void*, bool(*)(void*, void*));
static LLIterator* CreateIterator(struct LList_*);


static void swap(void* a, void* b, int size) {
    char* tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

LList* CreateLList(int dataSize) {
    LLNode* head = (LLNode*)malloc(sizeof(LLNode));
    if (head == NULL) {
        return NULL;
    }
    head->ele = NULL;
    head->next = NULL;
    LList* list = (LList*)malloc(sizeof(LList));
    if (list == NULL) {
        return NULL;
    }
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = Add;
    list->Push = Push;
    list->Pop = Pop;
    list->Empty = Empty;
    list->Find = Find;
    list->Sort = Sort;
    list->CreateIterator = CreateIterator;
    list->Delete = Delete;
    return list;
}

static int Add(LList* self, int index, void* data) {
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

static int Push(LList* self, void* data) {
    return Add(self, 0, data);
}

static void* Pop(LList* self) {
    if (self->head->next == NULL) {
        return NULL;
    }
    LLNode* tmp = self->head->next;
    self->head->next = self->head->next->next;
    self->length -= 1;
    return tmp->ele;
}

static bool Empty(LList* self) {
    return self->length == 0;
}

static void* Find(LList* self, void* data, bool(*equal)(void*, void*)) {
    LLNode* tmp = self->head->next;
    while (tmp != NULL) {
        if (equal(tmp->ele, data)) {
            return tmp->ele;
        }
        tmp = tmp->next;
    }
    return NULL;
}

static int Delete(LList* self, void* data, bool(*eq)(void*, void*)) {
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

static void* Next(LLIterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

static bool HasNext(LLIterator* self) {
    return self->current != NULL;
}

static void Sort(LList* self, bool(*gt)(void*, void*)) {
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

static LLIterator* CreateIterator(LList* self) {
    LLIterator* ite = (LLIterator*)malloc(sizeof(LLIterator));
    ite->current = self->head->next;
    ite->Next = Next;
    ite->HasNext = HasNext;
    return ite;
}