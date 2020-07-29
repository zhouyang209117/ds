#ifndef LINK_LIST_H
#define LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

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
    int (*Add)(struct LinkList_*, int, void*);
    int (*Push)(struct LinkList_*, void*);
    int (*Pop)(struct LinkList_*);
    bool (*Empty)(struct LinkList_*);
    void* (*Find)(struct LinkList_*, void*, bool(*)(void*, void*));
    void (*Traverse)(struct LinkList_*, void(*)(void*));
    void (*Sort)(struct LinkList_*, bool(*)(void*, void*));
    int (*Delete)(struct LinkList_*, void*, bool(*)(void*, void*));
    Iterator* (*CreateIterator)(struct LinkList_*);
}LinkList;

LinkList* CreateLinkList(int);
int Add(struct LinkList_*, int, void*);
int Push(struct LinkList_*, void*);
int Pop(struct LinkList_*);
bool Empty(struct LinkList_*);
void* Find(struct LinkList_*, void*, bool(*)(void*, void*));
void Traverse(struct LinkList_*, void(*)(void*));
void Sort(struct LinkList_*, bool(*)(void*, void*));
int Delete(struct LinkList_*, void*, bool(*)(void*, void*));
Iterator* CreateIterator(struct LinkList_*);

#ifdef __cplusplus
}
#endif

#endif