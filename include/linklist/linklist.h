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
    void* (*Get)(struct LinkList_*, int);
    int (*Find)(struct LinkList_*, void*, bool(*)(void*, void*));
    LinkNode* (*Next)(struct LinkList_*, LinkNode*);
    void (*Traverse)(struct LinkList_*, void(*)(void*));
    void (*Sort)(struct LinkList_*, int size, bool(*)(void*, void*));
}LinkList;

LinkList* CreateLinkList();
int Add(struct LinkList_*, int, void*, int);
void* Get(struct LinkList_*, int);
int Find(struct LinkList_*, void*, bool(*)(void*, void*));
LinkNode* Next(struct LinkList_*, LinkNode*);
void Traverse(struct LinkList_*, void(*)(void*));
void Sort(struct LinkList_*, int size, bool(*)(void*, void*));
#endif