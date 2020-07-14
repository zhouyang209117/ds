#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "linklist/linklist.h"

#define CN_START 19968
#define CN_END 40869
typedef struct Node_ {
    int num;
    wchar_t Char;
}Node;


void printNode(void* node) {
    Node* tmp = (Node*)node;
    wchar_t* a = (wchar_t*)malloc(sizeof(wchar_t));
    *a = tmp->Char;
    printf("%ls,%d\n", a, tmp->num);
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

void processChar(LinkList* list, wchar_t w) {
    if (w < CN_START || w > CN_END) {
        return;
    }
    Node newNode;
    newNode.Char = w;
    int index = list->Find(list, &newNode, equal);
    if (index == -1) {
        newNode.num = 1;
        int result = list->Add(list, 0, &newNode, sizeof(Node));
        if (result != 0) {
            printf("add error\n");
            return;
        }
    } else {
        Node* current = (Node*)(list->Get(list, index));
        current->num += 1;
    }
}

bool lt(void* a1, void* a2) {
    Node* s1 = (Node*)a1;
    Node* s2 = (Node*)a2;
    if (s1->num > s2->num) {
        return false;
    } else {
        return true;
    }
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LinkList* list = CreateLinkList();
    FILE * fin;
    wchar_t wc;
    fin=fopen ("a.txt","r");
    while((wc=fgetwc(fin))!=WEOF){
        processChar(list, wc);
    }
    fclose(fin);
    printf("len=%zu\n", list->length);
    list->Sort(list, sizeof(Node), lt);
    list->Traverse(list, printNode);
    return 0;
}