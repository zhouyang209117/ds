#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include <list/link.h>

static int         Add           (struct LList_*, int, void*);
static bool        Empty         (struct LList_*);
static int         Find          (struct LList_*, void*);
static void*       Get           (struct LList_*, int);
static void        Sort          (struct LList_*);
static int         Delete        (struct LList_*, void*);
static LLIterator* CreateIterator(struct LList_*);

static void swap(void* a, void* b, int size) {
    char* tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

LList* CreateLList(int dataSize, Comparator* comparator) {
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
    list->comparator = comparator;
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = Add;
    list->Find = Find;
    list->Get = Get;
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

static int Find(LList* self, void* data) {
    LLNode* tmp = self->head->next;
    for (int i = 0; tmp; i++, tmp = tmp->next) {
        if (self->comparator->Equal(tmp->ele, data)) {
            return i;
        }
    }
    return -1;
}

static void* Get(LList* self, int index) {
    LLNode* tmp = self->head->next;
    for (int i = 0; i < index && tmp; i++, tmp = tmp->next) {
    }
    return tmp ? tmp->ele : NULL;
}

static int Delete(LList* self, void* data) {
    LLNode* current = self->head;
    while (current->next != NULL) {
        if (self->comparator->Equal(current->next->ele, data)) {
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

static void Sort(LList* self) {
    LLNode* first = self->head->next;
    for (int i = self->length - 1 ; i > 0; i--) {
        LLNode* p1 = first;
        for (int j = 0; j < i; j++) {
            if (self->comparator->CompareTo(p1->ele, p1->next->ele)) {
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