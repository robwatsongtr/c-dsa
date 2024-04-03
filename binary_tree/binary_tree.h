#ifndef BIN_TREE_H
#define BIN_TREE_H

// structure for a binary tree node that can store a char
typedef struct TreeNodeChar {
    char* data;
    struct TreeNodeChar* left;
    struct TreeNodeChar* right;
} TreeNodeChar;


#endif