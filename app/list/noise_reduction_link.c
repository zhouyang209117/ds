#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include "list/link.h"

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

void processChar(LList* list, wchar_t w) {
    if (w < CN_START || w > CN_END) {
        return;
    }
    Node newNode;
    newNode.Char = w;
    Node* existNode = list->Find(list, &newNode, equal);
    if (existNode == NULL) {
        newNode.num = 1;
        int result = list->Add(list, 0, &newNode);
        if (result != 0) {
            printf("add error\n");
            return;
        }
    } else {
        existNode->num += 1;
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

int step1() {
    FILE* fin = fopen ("1.txt","r");
    FILE* fout1 = fopen ("2.txt","w");
    if (fin == NULL) {
        printf("read file error\n");
        return 1;
    }
    if (fout1 == NULL) {
        printf("write file error\n");
        return 1;
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
    return 0;
}

void step2() {
    LList* list = CreateLList(sizeof(Node));
    wchar_t wc;
    FILE* fin = fopen ("2.txt","r");
    while ((wc = fgetwc(fin)) != WEOF){
        processChar(list, wc);
    }
    fclose(fin);
    list->Sort(list, lt);
    FILE* fout = fopen ("3.txt","w");
    LLIterator *ite = list->CreateIterator(list);
    while (ite->HasNext(ite)) {
        Node* node = (Node*)(ite->Next(ite));
        fwprintf(fout, L"%lc,%d\n", node->Char, node->num);
    }
    fclose(fout);
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    int result = step1();
    if (result != 0) {
        return 1;
    }
    step2();
    return 0;
}