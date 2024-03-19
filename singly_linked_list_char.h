#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node;

struct Node* createNodeChar(char* data);
void pushFrontChar(struct Node** headRef, char* data);
char* popFrontChar(struct Node** headRef);
void appendChar(struct Node** headRef, char* data);
void printListChar(struct Node* head);

#endif