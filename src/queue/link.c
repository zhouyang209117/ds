#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <code/code.h>
#include <queue/link.h>

int   Enter (LQueue*, void*);
void* Delete(LQueue*);
bool  Empty (LQueue*);

LQueue* CreateLQueue(int dataSize) {
    LQueue* queue = (LQueue*)malloc(sizeof(LQueue));
    if (queue == NULL) {
        return NULL;
    }
    LQNode* head = (LQNode*)malloc(sizeof(LQNode));
    if (head == NULL) {
        return NULL;
    }
    head->next = NULL;
    queue->front = head;
    queue->rear = head;
    queue->dataSize = dataSize;
    queue->Enter = Enter;
    queue->Delete = Delete;
    queue->Empty = Empty;
    return queue;
}

int Enter(LQueue* queue, void* data) {
    if (queue == NULL) {
        return 1;
    }
    LQNode* newNode = (LQNode*)malloc(sizeof(LQNode));
    if (newNode == NULL) {
        return 1;
    }
    newNode->next = NULL;
    char* newData = (char*)malloc(queue->dataSize);
    if (newData == NULL) {
        return 1;
    }
    memcpy(newData, data, queue->dataSize);
    newNode->ele = newData;
    queue->rear->next = newNode;
    queue->rear = newNode;
    return 0;
}

void* Delete(LQueue* queue) {
    if (queue->front == queue->rear) {
        return NULL;
    }
    LQNode* result = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (result == queue->rear) {
        queue->rear = queue->front;
    }
    return result->ele;
}

bool Empty(LQueue* queue) {
    return queue->front == queue->rear;
}