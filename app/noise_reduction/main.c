#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "linklist/linklist.h"

#define CN_START 19968
#define CN_END 40869

#define TAG_START '<'
#define TAG_END '>'
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

void step1() {
    FILE* fin = fopen ("1.txt","r");
    FILE* fout1 = fopen ("2.txt","w");
    if (fin == NULL) {
        printf("read file error\n");
        return;
    }
    if (fout1 == NULL) {
        printf("write file error\n");
        return;
    }
    bool needWrite = true;
    wchar_t wc;
    while ((wc = fgetwc(fin)) != WEOF) {
        if (wc == btowc(TAG_START)) {
            needWrite = false;
            continue;
        }
        if (wc == btowc(TAG_END)) {
            needWrite = true;
            continue;
        }
        if (needWrite) {
            fputwc(wc, fout1);
        }
    }
    fclose(fin);
    fclose(fout1);
}

void step2() {
    LinkList* list = CreateLinkList();
    wchar_t wc;
    FILE* fin = fopen ("2.txt","r");
    while ((wc = fgetwc(fin)) != WEOF){
        processChar(list, wc);
    }
    fclose(fin);
    list->Sort(list, sizeof(Node), lt);
    FILE* fout = fopen ("3.txt","w");
    LinkNode* current = NULL;
    do {
        current = list->Next(list, current);
        if (current != NULL) {
            Node* node = (Node*)(current->ele);
            fwprintf(fout, L"%lc,%d\n", node->Char, node->num);
        }
    } while(current != NULL);
    fclose(fout);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    step1();
    step2();
    return 0;
}