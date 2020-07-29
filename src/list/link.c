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

LinkList* CreateLinkList(int dataSize) {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->ele = NULL;
    head->next = NULL;
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->dataSize = dataSize;
    list->head = head;
    list->Add = Add;
    list->Push = Push;
    list->Pop = Pop;
    list->Empty = Empty;
    list->Find = Find;
    list->Traverse = Traverse;
    list->Sort = Sort;
    list->CreateIterator = CreateIterator;
    list->Delete = Delete;
    list->length = 0;
    return list;
}

int Add(LinkList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    LinkNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
    char* newData = (char*)malloc(self->dataSize);
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    newNode->next = tmp->next;
    tmp->next = newNode;
    self->length += 1;
    return 0;
}

int Push(LinkList* self, void* data) {
    return Add(self, 0, data);
}

int Pop(LinkList* self) {
    if (self->head->next == NULL) {
        return ENOTFOUND;
    }
    LinkNode* tmp = self->head->next;
    self->head->next = self->head->next->next;
    self->length -= 1;
    free(tmp);
    return 0;
}

bool Empty(LinkList* self) {
    return self->length == 0;
}

void* Find(LinkList* self, void* data, bool(*equal)(void*, void*)) {
    LinkNode* tmp = self->head->next;
    while (tmp != NULL) {
        if (equal(tmp->ele, data)) {
            return tmp->ele;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int Delete(LinkList* self, void* data, bool(*eq)(void*, void*)) {
    LinkNode* current = self->head;
    while (current->next != NULL) {
        if (eq(current->next->ele, data)) {
            LinkNode* tmp = current->next;
            current->next = tmp->next;
            free(tmp);
            self->length -= 1;
            return 0;
        }
        current = current->next;
    }
    return ENOTFOUND;
}

void* Next(Iterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

bool HasNext(Iterator* self) {
    return self->current != NULL;
}

void Traverse(LinkList* self, void(*traverse)(void*)) {
    LinkNode* tmp = self->head->next;
    while (tmp != NULL) {
        traverse(tmp->ele);
        tmp = tmp->next;
    }
}

void Sort(LinkList* self, bool(*gt)(void*, void*)) {
    LinkNode* first = self->head->next;
    for (int i = self->length - 1 ; i > 0; i--) {
        LinkNode* p1 = first;
        for (int j = 0; j < i; j++) {
            if (gt(p1->ele, p1->next->ele)) {
                swap(p1->ele, p1->next->ele, self->dataSize);
            }
            p1 = p1->next;
        }
    }
}

Iterator* CreateIterator(LinkList* self) {
    Iterator* ite = (Iterator*)malloc(sizeof(Iterator));
    ite->current = self->head->next;
    ite->next = Next;
    ite->hasNext = HasNext;
    return ite;
}