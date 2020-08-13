#ifndef DS_LINK_QUEUE_H
#define DS_LINK_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct LQNode_ { // link queue node
    void* ele;
    struct LQNode_* next;
}LQNode;

typedef struct LQueue_ {
    int     dataSize;
    LQNode* front;
    LQNode* rear;
    int     (*Enter) (struct LQueue_*, void*);
    void*   (*Delete)(struct LQueue_*);
    int     (*Empty) (struct LQueue_*);
}LQueue;

LQueue* CreateLQueue(int);//create link queue
#ifdef __cplusplus
}
#endif

#endif