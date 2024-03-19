#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list_char.h"

struct Node {
    char* data; // rocking the strings 
    struct Node* next; // pointer to another node struct 
};

// returns a pointer to a new node of type Node 
struct Node* createNode(char* data) {
    // allocate size of struct of heap and assign it to a pointer named newNode of type Node 
    struct Node* newNode = malloc(sizeof(struct Node));
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
void pushFront(struct Node** headRef, char* data) {
    struct Node* newNode = createNode(data);

    // Link up the new node to the head,
    newNode->next = *headRef; 
    
    // Head pointer is assigned to the new node, making it the new head 
    *headRef = newNode; 
}

char* popFront(struct Node** headRef) {
    struct Node* head; // declare new head pointer 
    char* result;

    // copy the address of the first node into head variable 
    head = *headRef;

    // get the data 
    result = head->data;

    // head pointer is now assigned to the next node, removing the link 
    *headRef = head->next;

    // free the memory 
    free(head);

    return result;
}

void append(struct Node** headRef, char* data) {
    struct Node* newNode = createNode(data);
    // empty list check
    if (*headRef == NULL) {
        *headRef = newNode;
        return; 
    }
    // traverse list to end 
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // wire it up at the very end
    temp->next = newNode; 
}


void printList(struct Node* head) {
    struct Node* current = head;
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

