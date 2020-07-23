#ifndef C_LINK_LIST_H
#define C_LINK_LIST_H

typedef struct LinkNode {
    void* ele;
    struct LinkNode* next;
}LinkNode;

typedef struct Iterator_ {
    LinkNode* current;
    LinkNode* head;
    bool (*hasNext)(struct Iterator_*);
    void* (*next)(struct Iterator_*);
} Iterator;

typedef struct LinkList_ {
    LinkNode *head;
    size_t length;
    int dataSize;
    int (*Add)(struct LinkList_*, int, void*);
    int (*Delete)(struct LinkList_*, void*, bool(*eq)(void*, void*));
    Iterator* (*CreateIterator)(struct LinkList_*);
}LinkList;

LinkList* CreateLinkList(int);
int Add(LinkList*, int, void*);
int Delete(struct LinkList_*, void*, bool(*eq)(void*, void*));
Iterator* CreateIterator(struct LinkList_*);
#endif