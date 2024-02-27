#include <stdio.h>
#include <stdlib.h>

struct Node {
    // payload 
    int data; 
    // pointer to another node struct 
    struct Node* next; 
};

// returns a pointer to a new node
struct Node* createNode(int data) {
    // allocate size of struct of heap and assign it to a pointer of type Node 
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode = NULL) {
        printf('Memory allocation failed\n');
        exit(1);
    };

    newNode->data = data;
    newNode->next = NULL;

    return newNode;

}
