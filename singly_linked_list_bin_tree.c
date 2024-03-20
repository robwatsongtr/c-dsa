#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_bin_tree.h"

// structure for a binary tree node that can store a char
typedef struct TreeNodeChar {
    char* data;
    TreeNodeChar* left;
    TreeNodeChar* right;
} TreeNodeChar;

// structure for a linked list node that can store a binary tree node type. 
typedef struct ListNode {
    TreeNodeChar* tree_node;
    ListNode* next;
} ListNode;

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

// Create a linked list node that can store type TreeNodeChar above. Teamwork!
ListNode* createListNode(TreeNodeChar* treeNode) {
    ListNode* newListNode = malloc(sizeof(ListNode));
    if (newListNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    } 

    newListNode->tree_node = treeNode; 
    newListNode->next = NULL;

    return newListNode; 
}

// Push and Pop front of list 
void pushFrontBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode) {
    ListNode* newNode = createListNode(treeNode);
    newNode->next = *headRef;
    *headRef = newNode;
}

TreeNodeChar* popFrontBinTreeNode(ListNode** headRef) {
    ListNode* head;
    TreeNodeChar* returnedTreeNode;

    head = *headRef;
    returnedTreeNode = head->tree_node;
    *headRef = head->next;

    free(head);

    return returnedTreeNode;
}

// append to end of list 
void appendBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode) {
    ListNode* newNode = createListNode(treeNode);

    if (*headRef == NULL) {
        *headRef = newNode;
        return; 
    }

    ListNode* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode; 
}