#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "linklist/linklist.h"

typedef struct Node_ {
    int num;
    wchar_t Char;
}Node;


void printNode(void* node) {
    Node* tmp = (Node*)node;
    printf("num=%ls,name=%d\n", tmp->Char, tmp->num);
}

bool equal(void* a, void* b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    if(((Node*)a)->Char == ((Node*)b)->Char) {
        return true;
    } else {
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LinkList* list = CreateLinkList();
    return 0;
}