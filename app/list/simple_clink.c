#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode_ {
    int data;
    struct LNode_* next;
}LNode;

void Init(LNode** head) {
    *head = (LNode*)malloc(sizeof(LNode));
    (*head)->next = *head;
}

int Add(LNode* head, int index, int data) {
    LNode* current = head;
    for (int i = 0; i < index; i++, current = current->next) {
    }
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

int Delete(LNode* head, int data) {
    int i = 0;
    for (LNode* current = head; current != head || i == 0 ;current = current->next, i++) {
        if (current->next->data == data) {
            LNode* tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            return 0;
        }
    }
    return -1;
}

int Find(LNode* head, int data) {
    LNode* current = head->next;
    for (int i = 0; current != head || i == 0; i++, current = current->next) {
        if (current->data == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    LNode* head;
    Init(&head);
    Add(head, 0, 1);
    Add(head, 1, 2);
    Add(head, 0, 3);
    Add(head, 3, 4);
    Add(head, 0, 5);
    Add(head, 1, 6);
    for (LNode* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    Delete(head, 5);
    printf("delete\n");
    for (LNode* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    Delete(head, 4);
    printf("delete\n");
    for (LNode* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    Delete(head, 3);
    printf("delete\n");
    for (LNode* current = head->next; current != head; current = current->next) {
        printf("%d\n", current->data);
    }
    int result = Find(head, 6);
    printf("find:%d\n", result);
    result = Find(head, 2);
    printf("find:%d\n", result);
    result = Find(head, -1);
    printf("find:%d\n", result);
}