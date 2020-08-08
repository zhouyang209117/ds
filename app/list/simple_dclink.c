#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_ {
    int data;
    struct Node_* pre;
    struct Node_* next;
}Node;

void Init(Node** head) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->pre = *head;
    (*head)->next = *head;
}

int Add(Node* head, int index, int data) {
    Node* current = head;
    int i = 0;
    for (; i < index; i++, current = current->next) {
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current->next;
    newNode->pre = current;
    current->next->pre = newNode;
    current->next = newNode;
    return 0;
}

int Delete(Node* head, int data) {
    for (Node* current = head->next; current != head;current = current->next) {
        if (current->data == data) {
            current->next->pre = current->pre;
            current->pre->next = current->next;
            free(current);
            return 0;
        }
    }
    return -1;
}

int Find(Node* head, int data) {
    int i = 0;
    for (Node* current = head->next; current != head; current = current->next, i++) {
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
    Add(head, 1, 2);
    Add(head, 0, 3);
    Add(head, 3, 4);
    Add(head, 0, 5);
    Add(head, 1, 6);
    printf("next\n");
    for (Node* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    printf("pre\n");
    for (Node* current = head->pre; current != head; current = current->pre) {
        printf("%d\n", current->data);
    }
    Delete(head, 5);
    printf("delete\n");
    for (Node* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    Delete(head, 4);
    printf("delete\n");
    for (Node* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    Delete(head, 3);
    printf("delete\n");
    for (Node* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    int result = Find(head, 6);
    printf("find:%d\n", result);
    result = Find(head, 2);
    printf("find:%d\n", result);
    result = Find(head, -1);
    printf("find:%d\n", result);
}