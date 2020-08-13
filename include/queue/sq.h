#ifndef DS_SQ_QUEUE_H
#define DS_SQ_QUEUE_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
#define SQ_QUEUE_INIT_SIZE 16
typedef struct SqQueue_ {
    int   dataSize;
    void* ele;
    int   total;
    int   front;
    int   rear;
    int   (*Enter) (struct SqQueue_*, void*);
    void* (*Delete)(struct SqQueue_*);
    bool  (*Empty) (struct SqQueue_*);
}SqQueue;

SqQueue* CreateSqQueue(int);
#ifdef __cplusplus
}
#endif

#endif