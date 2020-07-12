#ifndef SQ_LIST_H
#define SQ_LIST_H
typedef struct SqList_ {
    int* ele;
    int length;
    int total;
    int (*Add)(struct SqList_ *a, int);
}SqList;

SqList* CreateSqList(int total);
int Add(SqList*, int);
#endif