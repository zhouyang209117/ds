#ifndef DS_BI_TREE_H
#define DS_BI_TREE_H

typedef enum Child_ {LEFT, RIGHT} Child;

typedef struct BiNode_ { // Binary tree node
    void* data;
    struct BiNode_* l;
    struct BiNode_* r;
}BiNode;

typedef struct Bi_ { // Binary tree
    int size;
    BiNode* root;
    int (*Add)(struct Bi_*, void*, int, void*);
}Bi;

Bi* CreateBi();
int Add(struct Bi_*, void*, int, void*);
#endif
