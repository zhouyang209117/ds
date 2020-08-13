#include <queue/sq.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int   Enter (SqQueue* queue, void*);
void* Delete(SqQueue* queue);
bool  Empty (SqQueue* queue);

SqQueue* CreateSqQueue(int dataSize) {
    SqQueue* queue = (SqQueue*)malloc(sizeof(SqQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->dataSize = dataSize;
    queue->front = 0;
    queue->rear = 0;
    queue->total = SQ_QUEUE_INIT_SIZE;
    queue->ele = (char*)malloc(dataSize * SQ_QUEUE_INIT_SIZE);
    queue->Enter = Enter;
    queue->Delete = Delete;
    queue->Empty = Empty;
    return queue;
}

int Enter(SqQueue* queue, void* data) {
    if (queue == NULL) {
        return 1;
    }
    if ((queue->rear + 1) % queue->total == queue->front) {
        return 1;
    }
    memcpy(queue->ele + queue->rear * queue->dataSize, data, queue->dataSize);
    queue->rear = (queue->rear + 1) % queue->total;
    return 0;
}

void* Delete(SqQueue* queue) {
    if (queue == NULL) {
        return NULL;
    }
    if (queue->front == queue->rear) {
        return NULL;
    }
    char* result = (char*)malloc(sizeof(queue->dataSize));
    if (result == NULL) {
        return NULL;
    }
    memcpy(result, queue->ele + queue->dataSize * queue->front,
           queue->dataSize);
    queue->front = (queue->front + 1) % queue->total;
    return result;
}

bool Empty(SqQueue* queue) {
    return queue->front == queue->rear;
}