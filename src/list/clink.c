#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list/clink.h"

LinkList* CreateLinkList(int dataSize) {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->ele = NULL;
    head->next = head;
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->dataSize = dataSize;
    list->head = head;
    list->length = 0;

    list->Add = Add;
    return list;
}

void add(LinkList* self, int index, void* data) {
    LinkNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
    if (newNode == NULL) {

    }
    char* newData = (char*)malloc(self->dataSize);
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    newNode->next = tmp->next;
    tmp->next = newNode;
    self->length += 1;
}

int Add(LinkList* self, int index, void* data) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    if (self->length == 0) {
        add(self, 0, data);
    } else {
        add(self, index % self->length, data);
    }
    return 0;
}