#include <stdio.h>
#include "singly_linked_list_bin_tree.h"
#include <stdlib.h>

// make a function that returns an inorder DFS on a tree as a linked list 


int main() {
    struct TreeNodeChar* root = createTreeNodeChar("root");
    struct TreeNodeChar* node2 = createTreeNodeChar("node_2");
    struct TreeNodeChar* node3 = createTreeNodeChar("node_3");
    struct TreeNodeChar* node4 = createTreeNodeChar("node_4");
    struct TreeNodeChar* node5 = createTreeNodeChar("node_5");
    struct TreeNodeChar* node6 = createTreeNodeChar("node_6");
    struct TreeNodeChar* node7 = createTreeNodeChar("node_7");

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5; 
    node3->left = node6;
    node3->right = node7;

    printf("Inorder traversal: ");
    printf("\n");
    printInorderTraversal(root);
    printf("\n");

    return 0;
}