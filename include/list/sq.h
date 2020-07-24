#ifndef SQ_LIST_H
#define SQ_LIST_H

#define SE_LIST_INIT_SIZE 16 // 为了动态扩展,缩短方便,必须是偶数
typedef struct Iterator_ {
    void* ele;
    int index;
    int length;
    bool (*hasNext)(struct Iterator_*);
    void* (*next)(struct Iterator_*,  int);
} Iterator;

typedef struct SqList_ {
    void* ele;
    int length;
    int total;
    int dataSize;
    int (*Add)(struct SqList_*, int, void*);
    void* (*Get)(struct SqList_*, int);
    int (*Set)(struct SqList_*, int, void*);
    int (*Remove)(struct SqList_*, int);
    int (*Find)(struct SqList_*, void*, bool(*)(void*, void*));
    void (*Sort)(struct SqList_*, bool(*)(void*, void*));
    void (*Traverse)(struct SqList_*, void(*)(void*));
    Iterator* (*CreateIterator)(struct SqList_*);
}SqList;

SqList* CreateSqList(int);
int Add(SqList*, int, void*);
void* Get(SqList*, int);
int Set(struct SqList_*, int, void*);
int Remove(struct SqList_*, int);
int Find(struct SqList_*, void*, bool(*)(void*, void*));
void Sort(struct SqList_*, bool(*)(void*, void*));
void Traverse(struct SqList_*, void(*)(void*));
Iterator* CreateIterator(struct SqList_*);
#endif