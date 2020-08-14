#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stack/link.h>

void con(int N, int d) {
    LStack* stack = CreateLStack(sizeof(int));
    do {
        int a = N % d;
        stack->Push(stack, &a);
        N /= d;
    } while(N != 0);
    while (!stack->Empty(stack)) {
        printf("%d", *((int*)stack->Pop(stack)));
    }
}

int main() {
    con(211987, 8);
    return 0;
}