#ifndef DS_BINARY_TREE_H
#define DS_BINARY_TREE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <list/sq.h>
#include <stack/link.h>
typedef struct BiNode_ {
    struct BiNode_* l;
    struct BiNode_* r;
    void* data;
}BiNode;

typedef struct BITIterator_ { // binary tree iterator
    LStack* stack;
    BiNode* current;
    bool   (*HasNext)(struct BITIterator_*);
    void*  (*Next)   (struct BITIterator_*);
} BITIterator;

typedef struct BiTree_ {
    int nodeNum;
    int dataSize;
    BiNode* head;
    BITIterator* (*CreateBITIterator)(struct BiTree_*);
}BiTree;


BiTree* CreateBiTree(SqList*, bool(*)(void*));

#ifdef __cplusplus
}
#endif

#endif
