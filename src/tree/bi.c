#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree/bi.h"

Bi* CreateBi() {
    Bi* tree = (Bi*)malloc(sizeof(Bi));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

int Add(Bi* bi, void* parent, int child, void* data, int size) {
    if (parent == NULL) {
        if (bi->root == NULL) {
            BiNode* root = (BiNode*)malloc(sizeof(BiNode));
            char* newData = (char*)malloc(size);
            memcpy(newData, data, size);
            root->data = newData;
            root->l = NULL;
            root->r = NULL;
            bi->root = root;
            bi->size = 1;
            return 0;
        } else {
            return 1;
        }
    }

}