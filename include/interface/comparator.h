#ifndef DS_INTERFACE_H
#define DS_INTERFACE_H
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Comparator_ {
    bool    (*CompareTo)(void*, void*);
    bool    (*Equal)    (void*, void*);
} Comparator;

#ifdef __cplusplus
}
#endif
#endif