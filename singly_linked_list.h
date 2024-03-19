#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;

struct Node* createNode(char* data);
void pushFront(struct Node** headRef, char* data);
char* popFront(struct Node** headRef);
void append(struct Node** headRef, char* data);
void printList(struct Node* head);

#endif