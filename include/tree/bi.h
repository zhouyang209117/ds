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
    int (*Add)(struct Bi_*, void*, int, void*, int);
    BiNode* (*Get)(struct Bi_*);
}Bi;

Bi* CreateBi();
BiNode* Get(Bi*);
int Add(struct Bi_*, void*, int, void*, int);
#endif
