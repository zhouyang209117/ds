#ifndef LINK_LIST_H
#define LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LLNode_ { // link list node
    void* ele;
    struct LLNode_* next;
}LLNode;

typedef struct LLIterator_ { // link list iterator
    LLNode* current;
    bool    (*HasNext)(struct LLIterator_*);
    void*   (*Next)   (struct LLIterator_*);
} LLIterator;

typedef struct LList_ {
    LLNode*   head;
    size_t    length;
    int       dataSize;
    int       (*Add)           (struct LList_*, int, void*);
    int       (*Push)          (struct LList_*, void*);
    int       (*Pop)           (struct LList_*);
    bool      (*Empty)         (struct LList_*);
    void*     (*Find)          (struct LList_*, void*, bool(*)(void*, void*));
    void      (*Traverse)      (struct LList_*, void(*)(void*));
    void      (*Sort)          (struct LList_*, bool(*)(void*, void*));
    int       (*Delete)        (struct LList_*, void*, bool(*)(void*, void*));
    LLIterator* (*CreateIterator)(struct LList_*);
}LList;

LList*    LL_Create        (int);// link list create
int       LL_Add           (struct LList_*, int, void*);
int       LL_Push          (struct LList_*, void*);
int       LL_Pop           (struct LList_*);
bool      LL_Empty         (struct LList_*);
void*     LL_Find          (struct LList_*, void*, bool(*)(void*, void*));
void      LL_Traverse      (struct LList_*, void(*)(void*));
void      LL_Sort          (struct LList_*, bool(*)(void*, void*));
int       LL_Delete        (struct LList_*, void*, bool(*)(void*, void*));
LLIterator* LL_CreateIterator(struct LList_*);

#ifdef __cplusplus
}
#endif

#endif