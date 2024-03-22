#ifndef SINGLY_LINKED_LIST_BIN_TREE_H
#define SINGLY_LINKED_LIST_BIN_TREE_H

// structure for a binary tree node that can store a char
typedef struct TreeNodeChar {
    char* data;
    struct TreeNodeChar* left;
    struct TreeNodeChar* right;
} TreeNodeChar;

// structure for a linked list node that can store a binary tree node type. 
typedef struct ListNode {
    struct TreeNodeChar* tree_node;
    struct ListNode* next;
} ListNode;

TreeNodeChar* createTreeNodeChar(char* data);
ListNode* createListNode(TreeNodeChar* treeNode);

void pushFrontBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode);
TreeNodeChar* popFrontBinTreeNode(ListNode** headRef);
void appendBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode);
void printListBinTree(ListNode* head);

#endif
