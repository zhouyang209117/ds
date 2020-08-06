#include <stdio.h>
#include <stdlib.h>
#include <code/code.h>
#include <stdbool.h>

typedef struct Node_ {
    int data;
    struct Node_* next;
}Node;

void Init(Node** head) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->next = NULL;
}

int Add(Node* head, int index, int data) {
    if (index < 0) {
        return 1;
    }
    Node* current = head;
    for (int i = 0; i < index && current->next != NULL; i++) {
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return ENOMEM;
    }
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

int Delete(Node* head, int index) {
    if (index < 0) {
        return 1;
    }
    Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return 1;
    }
    Node* tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return 0;
}

int Find(Node* head, int data) {
    Node* current = head->next;
    for (int i = 0; current; i++, current = current->next) {
        if (current->data == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    Node* head;
    Init(&head);
    Add(head, 0, 1);
    Add(head, 0, 2);
    Add(head, 0, 3);
    Add(head, 2, 4);
    Add(head, 100, 5);
    Node* tmp = head->next;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("delete\n");
    Delete(head, 1);
    tmp = head->next;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    int result = Find(head, 5);
    printf("find index:%d", result);
    return 0;
}