#include <stdio.h>
#include <stdlib.h>
#include <code/code.h>

typedef struct Node_ {
    int* data;
    struct Node_* next;
}Node;

Node* CreateList() {
    Node* list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    return list;
}

int Add(Node* head, int index, int data) {
    Node* current = head;
    for (int i = 0; i < index && current->next != NULL; i++) {
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return ENOMEM;
    }
    int* newData = (int*)malloc(sizeof(int));
    *newData = data;
    newNode->data = newData;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

int main() {
    Node* list = CreateList();
    Add(list, 0, 1);
    Add(list, 0, 2);
    Add(list, 0, 3);
    Add(list, 2, 4);
    Add(list, 100, 5);
    Node* tmp = list->next;
    while (tmp != NULL) {
        printf("%d\n", *tmp->data);
        tmp = tmp->next;
    }
    return 0;
}