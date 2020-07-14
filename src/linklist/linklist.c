#include <stdlib.h>
#include <string.h>
#include "linklist/linklist.h"

LinkList* CreateLinkList() {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->ele = NULL;
    head->next = NULL;
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head = head;
    list->Add = Add;
    list->Traverse = Traverse;
    return list;
}

int Add(LinkList* self, int index, void* data, int size) {
    if (index < 0 || index > self->length) {
        return 1;
    }
    LinkNode* tmp = self->head;
    for (int i = index; i > 0; i--) {
        tmp = tmp->next;
    }
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
    char* newData = (char*)malloc(size);
    memcpy(newData, data, size);
    newNode->ele = newData;
    newNode->next = tmp->next;
    tmp->next = newNode;
    self->length += 1;
    return 0;
}

void Traverse(LinkList* self, void(*traverse)(void*)) {
    LinkNode* tmp = self->head->next;
    while (tmp != NULL) {
        traverse(tmp->ele);
        tmp = tmp->next;
    }
}