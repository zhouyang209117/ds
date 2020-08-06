#ifndef DS_LIST_LINK_H
#define DS_LIST_LINK_H

#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
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
    Comparator* comparator;
    LLNode*     head;
    int         length;
    int         dataSize;
    int         (*Add)            (struct LList_*, int, void*);
    bool        (*Empty)          (struct LList_*);
    int         (*Find)           (struct LList_*, void*);
    void*       (*Get)            (struct LList_*, int);
    void        (*Sort)           (struct LList_*);
    int         (*Delete)         (struct LList_*, void*);
    LLIterator* (*CreateIterator) (struct LList_*);
}LList;

LList*      CreateLList        (int, Comparator*);//create link list
#ifdef __cplusplus
}
#endif

#endif