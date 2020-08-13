#include <stack/sq.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


static int   Push (SqStack*, void*);
static void* Pop  (SqStack*);
static void* Top  (SqStack*);
static bool  Empty(SqStack*);

SqStack* CreateSqStack(int eleSize) {
    SqStack* stack = (SqStack*)malloc(sizeof(SqStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->total = SQ_STACK_INIT_SIZE;
    stack->ele = (char*)malloc(eleSize * SQ_STACK_INIT_SIZE);
    if (stack->ele == NULL) {
        return NULL;
    }
    stack->length = 0;
    stack->dataSize = eleSize;
    stack->Push = Push;
    stack->Pop = Pop;
    stack->Top = Top;
    stack->Empty = Empty;
    return stack;
}

static int Push(SqStack* stack, void* data) {
    if (stack == NULL) {
        return 1;
    }
    if (stack->length == stack->total) {
        stack->ele = (char*)realloc(stack->ele, (stack->length * 2) * stack->dataSize);
        if (stack->ele == NULL) {
            return 1;
        }
        stack->total = stack->length * 2;
    }
    memcpy(stack->ele + stack->length * stack->dataSize, data, stack->dataSize);
    stack->length++;
    return 0;
}

static void* Pop(SqStack* stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (stack->length == 0) {
        return NULL;
    }
    char* result = (char*)malloc(stack->dataSize);
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, stack->ele + (stack->length - 1) * stack->dataSize , stack->dataSize);
    stack->length--;
    if (stack->length * 2 < stack->total && stack->total > SQ_STACK_INIT_SIZE) {
        stack->ele = (char*)realloc(stack->ele, (stack->total / 2) * stack->dataSize);
        if (stack->ele == NULL) {
            return NULL;
        }
        stack->total = stack->total / 2;
    }
    return result;
}

static void* Top(SqStack* stack) {
    if (stack == NULL) {
        return NULL;
    }
    if (stack->length == 0) {
        return NULL;
    }
    char* result = (char*)malloc(stack->dataSize);
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, stack->ele + (stack->length - 1) * stack->dataSize , stack->dataSize);
    return result;
}

bool Empty(SqStack* stack) {
    return stack->length == 0;
}