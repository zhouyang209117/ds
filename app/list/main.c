#include <stdio.h>
#include "list/list.h"
int main() {
    SqList* list = CreateSqList(10);
    list->Add(list, 2);
    printf("%d\n", list->length);
    printf("%d\n", list->total);
    printf("%d\n", (list->ele)[0]);
}