#ifndef SQ_LIST_H
#define SQ_LIST_H
typedef struct SqList_ {
    void* ele;
    int length;
    int total;
    int (*Add)(struct SqList_*, void*, int);
    void* (*Get)(struct SqList_*, int, int);
}SqList;

SqList* CreateSqList(int, int);
int Add(SqList*, void*, int);
void* Get(SqList*, int, int);
#endif