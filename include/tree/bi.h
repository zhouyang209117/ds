#ifndef DS_BINARY_TREE_H
#define DS_BINARY_TREE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <list/sq.h>
typedef struct BiNode_ {
    struct BiNode_* l;
    struct BiNode_* r;
    void* data;
}BiNode;

typedef struct BiTree_ {
    int nodeNum;
    int dataSize;
    BiNode* head;
}BiTree;
BiTree* CreateBiTree(SqList*, bool(*)(void*));

#ifdef __cplusplus
}
#endif

#endif
