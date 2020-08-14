#include <stdio.h>
#include <stdbool.h>
#include <stack/link.h>

bool match(char* a, int num) {
    LStack* stack = CreateLStack(sizeof(char));
    for (int i = 0; i < num; i++) {
        switch (a[i]) {
            case '(':
            case '[':
            case '{':
                stack->Push(stack, a + i);
                break;
            case ')':
                if (stack->Empty(stack)) {
                    return false;
                }
                if (*((char*)stack->Top(stack)) == '(') {
                    stack->Pop(stack);
                } else {
                    return false;
                }
                break;
            case ']':
                if (stack->Empty(stack)) {
                    return false;
                }
                if (*((char*)stack->Top(stack)) == '[') {
                    stack->Pop(stack);
                } else {
                    return false;
                }
                break;
            case '}':
                if (stack->Empty(stack)) {
                    return false;
                }
                if (*((char*)stack->Top(stack)) == '{') {
                    stack->Pop(stack);
                } else {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
    return stack->Empty(stack);
}

int main() {
    char a0[] = "{(())}]";
    printf("%s%d\n", a0, match(a0, 7));
    char a1[] = "()]";
    printf("%s%d\n", a1, match(a1, 3));
    char a2[] = "{(())}";
    printf("%s%d\n", a2, match(a0, 6));
    return 0;
}