#ifndef DS_LIST_SQ_H
#define DS_LIST_SQ_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
#define SE_LIST_INIT_SIZE 16 // 为了动态扩展,缩短方便,必须是偶数
typedef struct Iterator_ {
    void* ele;
    int   index;
    int   length;
    int   dataSize;
    bool  (*HasNext)(struct Iterator_*);
    void* (*Next)   (struct Iterator_*);
} Iterator;

typedef struct SqList_ {
    Comparator* comparator;
    int         dataSize;
    void*       ele;
    int         length;
    int         total;
    int         (*Add)            (struct SqList_*, int, void*);
    void*       (*Get)            (struct SqList_*, int);
    int         (*Set)            (struct SqList_*, int, void*);
    int         (*Remove)         (struct SqList_*, int);
    int         (*Find)           (struct SqList_*, void*);
    void        (*Sort)           (struct SqList_*);
    Iterator*   (*CreateIterator) (struct SqList_*);
}SqList;

SqList* CreateSqList(int, Comparator*);
#ifdef __cplusplus
}
#endif

#endif