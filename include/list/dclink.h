#ifndef DS_LIST_DCLINK_H
#define DS_LIST_DCLINK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DCLNode_ { // double circular link Node
    void* ele;
    struct DCLNode_* next;
    struct DCLNode_* pre;
}DCLNode;

typedef struct DCLLIterator_ {
    DCLNode* current;
    DCLNode* head;
    bool (*HasNext)(struct DCLLIterator_*);
    void* (*Next)(struct DCLLIterator_*);
} DCLLIterator; // double circular link list iterator

typedef struct DCLList_ { //double circular link list
    DCLNode *head;
    size_t length;
    int dataSize;
    int (*Add)(struct DCLList_*, int, void*);
    DCLLIterator* (*CreateIterator)(struct DCLList_*);
}DCLList;

DCLList* CreateDCLList(int);
int Add(DCLList*, int, void*);
DCLLIterator* CreateDCLLIterator(DCLList*);
#ifdef __cplusplus
}
#endif

#endif