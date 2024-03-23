#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_bin_tree.h"

/*
All needed functionality for a stack or a queue, as of 3/20/24
*/

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

// Create a linked list node that can store type TreeNodeChar above. 
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

// --------------------------Push and Pop front of list--------------------------
void pushFrontBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode) {
    ListNode* newNode = createListNode(treeNode);

    // Set the next of the newly allocated node to the 'old head', which
    // is the current first node of the list 
    newNode->next = *headRef;

    // Now change the head pointer to point to the new new node, making it the 'new head'
    *headRef = newNode;
}

TreeNodeChar* popFrontBinTreeNode(ListNode** headRef) {
    if (*headRef == NULL) return NULL; // Return NULL if list is empty

    ListNode* head; // declare new head pointer 
    TreeNodeChar* returnedTreeNode; // variable to store the result obviously

    // copy address of first node into a new head pointer
    // head becomes the 'old head'
    head = *headRef; 

    // get the data
    returnedTreeNode = head->tree_node; 

    // new head pointer is the next node over now, unlinking 
    // that makes it the 'new head'
    *headRef = head->next; 

    // free the memory from the old head 
    free(head); 

    return returnedTreeNode;
}

// -------------------------Append to end of list-------------------------------
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

void printListBinTree(ListNode* head) {
    ListNode* current = head;
    int count = 0;

    while (current != NULL) {
        count++; 
        // this accesses the tree_node field in ListNode, then goes to the data field in tree_node
        printf("%s", current->tree_node->data);
        printf("\n");
        current = current->next;
    }
    printf("Length: %d\n", count);
    printf("\n");
}

// for bin tree 

void printInorderTraversal(TreeNodeChar* root) {
    if (root == NULL) return;

    printInorderTraversal(root->left);
    printf("%s ", root->data);
    printf("\n");
    printInorderTraversal(root->right);
}