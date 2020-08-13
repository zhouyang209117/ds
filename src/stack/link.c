#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include <stack/link.h>

static int   Push (LStack*, void*);
static void* Pop  (LStack*);
static void* Top  (LStack*);
static bool  Empty(LStack*);

LStack* CreateLStack(int dataSize) {
    LSNode* head = (LSNode*)malloc(sizeof(LSNode));
    if (head == NULL) {
        return NULL;
    }
    head->ele = NULL;
    head->next = NULL;
    LStack* stack = (LStack*)malloc(sizeof(LStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->dataSize = dataSize;
    stack->head = head;
    stack->Push = Push;
    stack->Pop = Pop;
    stack->Top = Top;
    stack->Empty = Empty;
    return stack;
}

static int Push(LStack* self, void* data) {
    if (self == NULL) {
        return -1;
    }
    if (data == NULL) {
        return -1;
    }
    if (self->head == NULL) {
        return -1;
    }
    LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
    if (newNode == NULL) {
        return -1;
    }
    char* newData = (char*)malloc(self->dataSize);
    if (newData == NULL) {
        return -1;
    }
    memcpy(newData, data, self->dataSize);
    newNode->ele = newData;
    newNode->next = self->head->next;
    self->head->next = newNode;
    return 0;
}

static void* Pop(LStack* self) {
    if (self == NULL) {
        return NULL;
    }
    if (self->head == NULL) {
        return NULL;
    }
    if (self->head->next == NULL) {
        return NULL;
    }
    LSNode* tmp = self->head->next;
    self->head->next = self->head->next->next;
    return tmp->ele;
}

static void* Top(LStack* self) {
    if (self == NULL) {
        return NULL;
    }
    if (self->head == NULL) {
        return NULL;
    }
    if (self->Empty(self)) {
        return NULL;
    }
    char* result = (char*)malloc(self->dataSize);
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, self->head->next->ele, self->dataSize);
    return result;
}

static bool Empty(LStack* self) {
    return self->head->next == NULL;
}