#include <stdio.h>
#include "tree/bi.h"
int main() {
    Bi* tree = CreateBi();
    printf("size=%d\n", tree->size);
    printf("root=%p\n", tree->root);
    return 0;
}