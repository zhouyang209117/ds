#include <stdlib.h>
#include <string.h>
#include "linklist/linklist.h"

LinkList* CreateLinkList() {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->ele = NULL;
    head->next = NULL;
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = head;
    return list;
}

int Add(LinkList* self, void* data, int size) {
    LinkNode* nextNode = self->head->next;
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
    char* newData = (char*)malloc(size);
    memcpy(newData, data, size);
    newNode->ele = newData;
    newNode->next = nextNode;
    self->head->next = newNode;
    self->length += 1;
    return 0;
}