#ifndef LINK_LIST_H
#define LINK_LIST_H
typedef struct LinkNode {
    void* ele;
    struct LinkNode* next;
}LinkNode;

typedef struct LinkList_ {
    LinkNode *head;
    size_t length;
    int (*Add)(struct LinkList_*, int, void*, int);
    void (*Traverse)(struct LinkList_*, void(*)(void*));
}LinkList;

LinkList* CreateLinkList();
int Add(struct LinkList_*, int, void*, int);
void Traverse(struct LinkList_*, void(*)(void*));
#endif