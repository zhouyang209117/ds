#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct LinkNode {
    void* ele;
    struct LinkNode* next;
}LinkNode;

typedef struct Iterator_ {
    LinkNode* current;
    bool (*hasNext)(struct Iterator_*);
    void* (*next)(struct Iterator_*);
} Iterator;

typedef struct LinkList_ {
    LinkNode *head;
    size_t length;
    int dataSize;
    int (*Add)(struct LinkList_*, int, void*, int);
    void* (*Get)(struct LinkList_*, int);
    int (*Find)(struct LinkList_*, void*, bool(*)(void*, void*));
    void (*Traverse)(struct LinkList_*, void(*)(void*));
    void (*Sort)(struct LinkList_*, bool(*)(void*, void*));
    Iterator* (*CreateIterator)(struct LinkList_*);
}LinkList;

LinkList* CreateLinkList(int);
int Add(struct LinkList_*, int, void*);
void* Get(struct LinkList_*, int);
int Find(struct LinkList_*, void*, bool(*)(void*, void*));
void Traverse(struct LinkList_*, void(*)(void*));
void Sort(struct LinkList_*, bool(*)(void*, void*));
Iterator* CreateIterator(struct LinkList_*);
#endif