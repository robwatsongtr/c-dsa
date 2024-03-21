#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_char.h"

typedef struct Node {
    char* data; // rocking the strings 
    struct Node* next; // pointer to another node struct 
} Node;

// returns a pointer to a new node of type Node 
Node* createNodeChar(char* data) {
    // allocate size of struct of heap and assign it to a pointer named newNode of type Node 
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    };

    // allocate memory for string
    newNode->data = malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // copy string into data field 
    strcpy(newNode->data, data);

    newNode->next = NULL;

    return newNode;
}

// We use a double pointer in order to be able to modify head pointer.
void pushFrontChar(Node** headRef, char* data) {
    Node* newNode = createNode(data);

    // Set the next of the newly allocated node to the 'old head', which
    // is the current first node of the list 
    newNode->next = *headRef; 
    
    // Now change the head pointer to point to the new new node, making it the 'new head'
    *headRef = newNode; 
}

char* popFrontChar(Node** headRef) {
    Node* head; // declare new head pointer 
    char* result; // variable to store the result obviously

    // copy address of first node into a new head pointer
    // head becomes the 'old head'
    head = *headRef;

    // get the data 
    result = head->data;

    // new head pointer is the next node over now, unlinking 
    // that makes it the 'new head'
    *headRef = head->next;

    // free the memory from the old head 
    free(head);

    return result;
}

void appendChar(Node** headRef, char* data) {
    Node* newNode = createNode(data);
    // empty list check
    if (*headRef == NULL) {
        *headRef = newNode;
        return; 
    }
    // traverse list to end 
    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // wire it up at the very end
    temp->next = newNode; 
}


void printListChar(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        count++; 
        printf("%s", current->data);
        printf("\n");
        current = current->next;
    }
    printf("Length: %d\n", count);
    printf("\n");
}

