#include <stdio.h>
#include "singly_linked_list_bin_tree.h"
#include <stdlib.h>

int main() {

    // create a binary tree nodes with some text as payload
    struct TreeNodeChar* treenode1 = createTreeNodeChar("example_text_1");
    struct TreeNodeChar* treenode2 = createTreeNodeChar("example_text_2");
    struct TreeNodeChar* treenode3 = createTreeNodeChar("example_text_3");

    // create a new list head 
    struct ListNode* newListHead = NULL;

    // add the nodes to front of list 
    pushFrontBinTreeNode(&newListHead, treenode1);
    pushFrontBinTreeNode(&newListHead, treenode2);
    pushFrontBinTreeNode(&newListHead, treenode3);

    printListBinTree(newListHead);

    // pop off front of list and display text
    struct TreeNodeChar* poppedItem1 = popFrontBinTreeNode(&newListHead);
    printf("popped item data:  %s\n", poppedItem1->data);
    printf("\n");

    printListBinTree(newListHead);

    // append to end of list 
    struct TreeNodeChar* treenode4 = createTreeNodeChar("APPEND");
    appendBinTreeNode(&newListHead, treenode4);

    printListBinTree(newListHead);

    return 0;
}