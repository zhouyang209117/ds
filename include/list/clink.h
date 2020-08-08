#ifndef DS_LIST_CLINK_H
#define DS_LIST_CLINK_H
#include <stdbool.h>
#include <interface/comparator.h>
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
    Comparator*  comparator;
    CLLNode      *head;
    int          length;
    int          dataSize;
    int          (*Add)           (struct CLList_*, int, void*);
    int          (*Delete)        (struct CLList_*, void*);
    int          (*Find)          (struct CLList_*, void*);
    void*        (*Get)           (struct CLList_*, int);
    CLLIterator* (*CreateIterator)(struct CLList_*);
}CLList;

CLList* CreateCLList(int, Comparator*);
#ifdef __cplusplus
}
#endif
#endif