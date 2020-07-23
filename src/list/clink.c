#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list/clink.h"
#include "code/code.h"

LinkList* CreateLinkList(int dataSize) {
    if (dataSize == 0) {
        return NULL;
    }
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    if (head == NULL) {
        return ENOMEM;
    }
    head->ele = NULL;
    head->next = head;
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    if (list == NULL) {
        return ENOMEM;
    }
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;
    list->Add = Add;
    list->Delete = Delete;
    return list;
}

int add(LinkList* self, int index, void* data) {
    LinkNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
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
}

int Add(LinkList* self, int index, void* data) {
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

void* Next(Iterator* self) {
    void* data = self->current->ele;
    self->current = self->current->next;
    return data;
}

bool HasNext(Iterator* self) {
    return self->current != self->head;
}

Iterator* CreateIterator(LinkList* self) {
    Iterator* ite = (Iterator*)malloc(sizeof(Iterator));
    if (ite == NULL) {
        return NULL;
    }
    ite->head = self->head;
    ite->current = self->head->next;
    ite->next = Next;
    ite->hasNext = HasNext;
    return ite;
}

int Delete(LinkList* self, void* data, bool(*eq)(void*, void*)) {
    if (self == NULL) {
        return EAGAIN;
    }
    LinkNode* current = self->head;
    while (current->next != self->head) {
        if (eq(current->next->ele, data)) {
            LinkNode* tmp = current->next;
            current->next = current->next->next;
            self->length -= 1;
            free(tmp);
            return 0;
        }
        current = current->next;
    }
    return ENOTFOUND;
}