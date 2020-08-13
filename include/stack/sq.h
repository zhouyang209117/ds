#ifndef DS_SQ_STACK_H
#define DS_SQ_STACK_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <interface/comparator.h>
#define SQ_STACK_INIT_SIZE 16 // 为了动态扩展,缩短方便,必须是偶数
typedef struct SqStack_ {
    int   dataSize;
    void* ele;
    int   length;
    int   total;
    int   (*Push) (struct SqStack_*, void*);
    void* (*Pop)  (struct SqStack_*);
    bool  (*Empty)(struct SqStack_*);
}SqStack;

SqStack* CreateSqStack(int);
#ifdef __cplusplus
}
#endif

#endif