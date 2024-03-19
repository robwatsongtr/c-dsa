#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNodeChar {
    char* data;
    TreeNodeChar* left;
    TreeNodeChar* right;
} TreeNodeChar;

typedef struct ListNode {
    TreeNodeChar* tree_node;
    ListNode* next;
} ListNode;



