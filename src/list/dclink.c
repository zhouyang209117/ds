#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include <list/dclink.h>

static int           Add               (DCLList*, int, void*);
static int           Delete            (DCLList*, void*);
static int           Find              (DCLList*, void*);
static void*         Get               (DCLList*, int);
static DCLLIterator* CreateDCLLIterator(DCLList*);

DCLList* CreateDCLList(int dataSize, Comparator* cmp) {
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
    list->cmp = cmp;
    list->dataSize = dataSize;
    list->head = head;
    list->Add = Add;
    list->Delete = Delete;
    list->Find = Find;
    list->Get = Get;
    list->CreateIterator = CreateDCLLIterator;
    list->length = 0;
    return list;
}

static int Add(DCLList* self, int index, void* data) {
    if (self == NULL) {
        return EAGAIN;
    }
    if (self->head == NULL) {
        return EAGAIN;
    }
    if (index < 0 || index > self->length) {
        return EAGAIN;
    }
    DCLNode* tmp = self->head;
    for (int i = 0; i < index; i++) {
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
    newNode->next = tmp->next;
    newNode->pre = tmp;
    tmp->next->pre = newNode;
    tmp->next = newNode;
    self->length += 1;
    return 0;
}

static int Delete(DCLList* self, void* data) {
    if (self == NULL) {
        return EAGAIN;
    }
    if (self->head == NULL) {
        return EAGAIN;
    }
    for (DCLNode* current = self->head->next; current != self->head;
            current = current->next) {
        if (self->cmp->Equal(current->ele, data)) {
            current->next->pre = current->pre;
            current->pre->next = current->next;
            free(current);
            self->length--;
            return 0;
        }
    }
    return ENOTFOUND;
}

int Find(DCLList* self, void* data) {
    if (self == NULL) {
        return -2;
    }
    if (self->head == NULL) {
        return -2;
    }
    int i = 0;
    for (DCLNode* current = self->head->next; current != self->head;
            current = current->next, i++) {
        if (self->cmp->Equal(current->ele, data)) {
            return i;
        }
    }
    return -1;
}

void* Get(DCLList* self, int index) {
    if (self == NULL) {
        return NULL;
    }
    if (self->head == NULL) {
        return NULL;
    }
    if (index < 0 || index >= self->length) {
        return NULL;
    }
    DCLNode* current = self->head->next;
    for (int i = 0; i < index;
         current = current->next, i++) {
    }
    return current->ele;
}

static void* Next(DCLLIterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

static bool HasNext(DCLLIterator* self) {
    return self->current != self->head;
}

static DCLLIterator* CreateDCLLIterator(DCLList* list) {
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