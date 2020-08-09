#ifndef DS_DCLINK_LIST_H
#define DS_DCLINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
typedef struct DCLNode_ { // double circular link Node
    void* ele;
    struct DCLNode_* next;
    struct DCLNode_* pre;
}DCLNode;

typedef struct DCLLIterator_ {
    DCLNode* current;
    DCLNode* head;
    bool     (*HasNext)(struct DCLLIterator_*);
    void*    (*Next)   (struct DCLLIterator_*);
} DCLLIterator; // double circular link list iterator

typedef struct DCLList_ { //double circular link list
    Comparator*   cmp;
    DCLNode*      head;
    size_t        length;
    int           dataSize;
    int           (*Add)           (struct DCLList_*, int, void*);
    int           (*Delete)        (struct DCLList_*, void*);
    int           (*Find)          (struct DCLList_*, void*);
    void*         (*Get)           (struct DCLList_*, int);
    DCLLIterator* (*CreateIterator)(struct DCLList_*);
}DCLList;

DCLList* CreateDCLList(int, Comparator*);
#ifdef __cplusplus
}
#endif

#endif