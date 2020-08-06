#ifndef DS_LINK_STACK_H
#define DS_LINK_STACK_H

#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
typedef struct LSNode_ { // link stack node
    void* ele;
    struct LSNode_* next;
}LSNode;

typedef struct LStack_ {
    Comparator* comparator;
    LSNode*     head;
    int         dataSize;
    int         (*Push)   (struct LStack_*, void*);
    void*       (*Pop)    (struct LStack_*);
    int         (*Empty)  (struct LStack_*);
}LStack;

LStack* CreateLStack (int);//create link stack
#ifdef __cplusplus
}
#endif

#endif