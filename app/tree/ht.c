#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <list/sq.h>



typedef struct {
    int num;
    wchar_t Char;
}Node;

typedef struct {
    int weight;
    int parent;
    int left;
    int right;
}HTNode;

Node* createNode(int num, wchar_t word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->Char = word;
    return newNode;
}

HTNode* createHTNode(int weight) {
    HTNode* newNode = (HTNode*)malloc(sizeof(HTNode));
    newNode->weight = weight;
    return newNode;
}

SqList* getInput() {
    SqList* list = CreateSqList(sizeof(Node));
    list->Add(list, list->length, createNode(1, L'中'));
    list->Add(list, list->length, createNode(2, L'国'));
    list->Add(list, list->length, createNode(3, L'人'));
    return list;
}

int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(sizeof(Node));
    SqList* input = getInput();
    SqList* htEle = CreateSqList(sizeof(HTNode));
    Iterator* ite = input->CreateIterator(input);
    while (ite->hasNext(ite)) {
        Node* current = (Node*)(ite->next(ite));
        htEle->Add(htEle, 0, createHTNode(current->num));
    }
//    printf("hello world\n");
    return 0;
}