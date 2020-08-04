#ifndef DS_LIST_CLINK_H
#define DS_LIST_CLINK_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct CLLNode_ { // circular linked list node
    void* ele;
    struct CLLNode_* next;
}CLLNode;

typedef struct CLLIterator_ {
    CLLNode* current;
    CLLNode* head;
    bool     (*HasNext)(struct CLLIterator_*);
    void*    (*Next)   (struct CLLIterator_*);
} CLLIterator;

typedef struct CLList_ {
    CLLNode      *head;
    int          length;
    int          dataSize;
    int          (*Add)           (struct CLList_*, int, void*);
    int          (*Delete)        (struct CLList_*, void*, bool(*eq)(void*, void*));
    CLLIterator* (*CreateIterator)(struct CLList_*);
}CLList;

CLList* CreateCLList(int);
#ifdef __cplusplus
}
#endif
#endif