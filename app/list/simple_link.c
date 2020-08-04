#include <stdio.h>
#include <stdlib.h>
#include <code/code.h>

typedef struct Node_ {
    int* data;
    struct Node_* next;
}Node;

Node* Init(Node* list) {
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
    Node head;
    Init(&head);
    Add(&head, 0, 1);
    Add(&head, 0, 2);
    Add(&head, 0, 3);
    Add(&head, 2, 4);
    Add(&head, 100, 5);
    Node* tmp = head.next;
    while (tmp != NULL) {
        printf("%d\n", *tmp->data);
        tmp = tmp->next;
    }
    return 0;
}