#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// We use a double pointer in order to be able to actually modify the passed in headRef.
void prepend(struct Node** headRef, char* data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef; // Link up the new node to the head,
    *headRef = newNode; // Head pointer is assigned to the new node, making it the new head 
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
    // wire it up
    temp->next = newNode; 
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s", current->data);
        printf("\n");
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* newListHead = NULL;

    prepend(&newListHead, "Peru");
    prepend(&newListHead, "Albania");
    prepend(&newListHead, "England");
    prepend(&newListHead, "New Zealand");
    prepend(&newListHead, "Germany");
    prepend(&newListHead, "Thailand");

    printf("\n");
    printList(newListHead);
    printf("\n");
    append(&newListHead, "APPEND");
    printList(newListHead);
    printf("\n");
    prepend(&newListHead, "PREPEND");
    printList(newListHead);

    return 0;
}