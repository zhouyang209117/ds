#ifndef SQ_LIST_H
#define SQ_LIST_H

#define SE_LIST_INIT_SIZE 20 // 为了实现动态扩展,缩短方便,必须是偶数
typedef struct SqList_ {
    void* ele;
    int length;
    int total;
    int (*Add)(struct SqList_*, int, void*, int);
    void* (*Get)(struct SqList_*, int, int);
    int (*Set)(struct SqList_*, int, int, void*);
    int (*Remove)(struct SqList_*, int, int);
    int (*Find)(struct SqList_*, void*, int, bool(*)(void*, void*));
    void (*Traverse)(struct SqList_*, int, void(*)(void*));
}SqList;

SqList* CreateSqList(int);
int Add(SqList*, int, void*, int);
void* Get(SqList*, int, int);
int Set(struct SqList_*, int, int, void*);
int Remove(struct SqList_*, int, int);
int Find(struct SqList_*, void*, int, bool(*)(void*, void*));
void Traverse(struct SqList_*, int, void(*)(void*));
#endif