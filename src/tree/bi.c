#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <list/link.h>
#include <tree/bi.h>
#include <list/sq.h>

static BITIterator* CreateBITIterator(BiTree*);

void create(BiNode** t, Iterator* ite, bool(*empty)(void* data)) {
    void* current = ite->Next(ite);
    if (empty(current)) {
        *t = NULL;
    } else {
        *t = (BiNode*)malloc(sizeof(BiNode));
        if (*t == NULL) {
            exit(1);
        }
        char* newData = (char*)malloc(ite->dataSize);
        if (newData == NULL) {
            exit(1);
        }
        memcpy(newData, current, ite->dataSize);
        (*t)->data = newData;
        create(&((*t)->l), ite, empty);
        create(&((*t)->r), ite, empty);
    }
}

BiTree* CreateBiTree(SqList* list, bool(*empty)(void*)) {
    BiTree* tree = (BiTree*)malloc(sizeof(BiTree));
    if (tree == NULL) {
        return NULL;
    }
    Iterator* ite = list->CreateIterator(list);
    if (ite == NULL) {
        return NULL;
    }
    tree->head = NULL;
    create(&tree->head, ite, empty);
    tree->dataSize = list->dataSize;
    tree->CreateBITIterator = CreateBITIterator;
    return tree;
}

static bool HasNext(BITIterator* ite) {
    return ite->current != NULL || !ite->stack->Empty(ite->stack);
}

static void* Next(BITIterator* ite) {
    BiNode* p = ite->current;
    while(p != NULL) {
        ite->stack->Push(ite->stack, &p);
        p = p->l;
    }
    BiNode** q = ite->stack->Pop(ite->stack);
    ite->current = (*q)->r;
    return (*q)->data;
}

static BITIterator* CreateBITIterator(BiTree* tree) {
    BITIterator* ite = (BITIterator*)malloc(sizeof(BITIterator));
    if (ite == NULL) {
        return NULL;
    }
    ite->current = tree->head;
    ite->stack = CreateLList(sizeof(BiNode**));
    if (ite->stack == NULL) {
        return NULL;
    }
    ite->Next = Next;
    ite->HasNext = HasNext;
    return ite;
}