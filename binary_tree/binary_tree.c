#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Create a binary tree node that can store type char 
TreeNodeChar* createTreeNodeChar(char* data) {
    TreeNodeChar* newTreeNode = malloc(sizeof(TreeNodeChar));
    if (newTreeNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // allocate memory for string
    newTreeNode->data = malloc(strlen(data) +1);
    if (newTreeNode->data == NULL) {
        printf("Memory allocation failed\n");
        free(newTreeNode); // Freeing the allocated TreeNodeChar
        exit(1);
    }
    strcpy(newTreeNode->data, data);

    newTreeNode->left = NULL;
    newTreeNode->right = NULL;

    return newTreeNode;
};