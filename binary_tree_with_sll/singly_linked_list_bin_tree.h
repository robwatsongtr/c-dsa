#ifndef SINGLY_LINKED_LIST_BIN_TREE_H
#define SINGLY_LINKED_LIST_BIN_TREE_H

struct TreeNodeChar;
struct ListNode;

TreeNodeChar* createTreeNodeChar(char* data);
ListNode* createListNode(TreeNodeChar* treeNode);
void pushFrontBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode);
TreeNodeChar* popFrontBinTreeNode(ListNode** headRef);
void appendBinTreeNode(ListNode** headRef, TreeNodeChar* treeNode);

#endif
