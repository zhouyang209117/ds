#include <stdbool.h>
#include <stdlib.h>
#include "tree/bi.h"

Bi* CreateBi() {
    Bi* tree = (Bi*)malloc(sizeof(Bi));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}