#include <stack/sq.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


static int   Push(SqStack*, void*);
static void* Pop(SqStack*);
static bool  Empty(SqStack*);

SqStack* CreateSqStack(int eleSize) {
    SqStack* stack = (SqStack*)malloc(sizeof(SqStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->total = SQ_STACK_INIT_SIZE;
    stack->ele = (char*)malloc(eleSize * SQ_STACK_INIT_SIZE);
    stack->length = 0;
    stack->dataSize = eleSize;
    stack->Push = Push;
    stack->Pop = Pop;
    stack->Empty = Empty;
    return stack;
}

static int Push(SqStack* stack, void* data) {
    if (stack == NULL) {
        return 1;
    }
    if (stack->length == stack->total) {
        stack->ele = (char*)realloc(stack->ele, (stack->length * 2) * stack->dataSize);
        stack->total = stack->length * 2;
    }
    for (int i = stack->length - 1; i >= 0; i--) {
        memcpy(stack->ele + (i + 1) * stack->dataSize,
               stack->ele + i * stack->dataSize, stack->dataSize);
    }
    memcpy(stack->ele, data, stack->dataSize);
    stack->length += 1;
    return 0;
}

static void* Pop(SqStack* stack) {
    if (stack == NULL) {
        return NULL;
    }
    char* result = (char*)malloc(stack->dataSize);
    memcpy(result, stack->ele, stack->dataSize);
    for (int i = 0; i < stack->length - 1; i++) {
        int offset1 = i * stack->dataSize;
        int offset2 = (i + 1) * stack->dataSize;
        memcpy(stack->ele + offset1, stack->ele + offset2, stack->dataSize);
    }
    stack->length -= 1;
    if (stack->length * 2 < stack->total && stack->total > SQ_STACK_INIT_SIZE) {
        stack->ele = (char*)realloc(stack->ele, (stack->total / 2) * stack->dataSize);
        stack->total = stack->total / 2;
    }
    return result;
}

bool Empty(SqStack* stack) {
    return stack->length == 0;
}