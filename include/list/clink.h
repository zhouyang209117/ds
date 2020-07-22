#ifndef C_LINK_LIST_H
#define C_LINK_LIST_H

typedef struct LinkNode {
    void* ele;
    struct LinkNode* next;
}LinkNode;

typedef struct LinkList_ {
    LinkNode *head;
    size_t length;
    int dataSize;
    int (*Add)(struct LinkList_*, int, void*);
}LinkList;

LinkList* CreateLinkList(int);
int Add(LinkList*, int, void*);
#endif