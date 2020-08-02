#ifndef SQ_LIST_H
#define SQ_LIST_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

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
    void*     ele;
    int       length;
    int       total;
    int       dataSize;
    int       (*Add)            (struct SqList_*, int, void*);
    void*     (*Get)            (struct SqList_*, int);
    int       (*Set)            (struct SqList_*, int, void*);
    int       (*Remove)         (struct SqList_*, int);
    int       (*Find)           (struct SqList_*, void*, bool(*)(void*, void*));
    void      (*Sort)           (struct SqList_*, bool(*)(void*, void*));
    Iterator* (*CreateIterator) (struct SqList_*);
}SqList;

SqList* CreateSqList(int);
#ifdef __cplusplus
}
#endif

#endif