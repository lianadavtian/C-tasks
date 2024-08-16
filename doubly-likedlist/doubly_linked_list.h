#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/mman.h>

typedef struct Node {
   int value;
   struct Node *prev;
   struct Node *next;
} Node;

typedef struct {
   Node *head;
   Node *tail;
   int size;
} DoublyLinkedList;

Node* creat(int value); 
void DoublyLinkedList_init(DoublyLinkedList *list); 
void DoublyLinkedList_destroy(DoublyLinkedList *list);
void DoublyLinkedList_copy(DoublyLinkedList *dest, const DoublyLinkedList *src);
void DoublyLinkedList_insertFront(DoublyLinkedList *list, int value);
void DoublyLinkedList_insertBack(DoublyLinkedList *list, int value);
void DoublyLinkedList_insertAfter(DoublyLinkedList *list, Node *node, int value);
void DoublyLinkedList_insert(DoublyLinkedList *list, int position, int value);
void DoublyLinkedList_insertBefore(DoublyLinkedList *list, Node *node, int value);
void DoublyLinkedList_removeFront(DoublyLinkedList *list);
void DoublyLinkedList_removeBack(DoublyLinkedList *list);
void DoublyLinkedList_removeNode(DoublyLinkedList *list, Node *node);
Node* DoublyLinkedList_search(DoublyLinkedList *list, int value);
int DoublyLinkedList_getSize(const DoublyLinkedList *list);
bool DoublyLinkedList_isEmpty(const DoublyLinkedList *list);
void DoublyLinkedList_printForward(const DoublyLinkedList *list);
void DoublyLinkedList_printBackward(const DoublyLinkedList *list);
void DoublyLinkedList_reverse(DoublyLinkedList *list);
void DoublyLinkedList_clear(DoublyLinkedList *list);

#endif // DOUBLY_LINKED_LIST_H
