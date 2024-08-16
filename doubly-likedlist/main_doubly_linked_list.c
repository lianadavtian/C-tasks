#include"doubly_linked_list.h"

int main()
{
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
	if(list == NULL)
	{
		perror("Malloc failed.");
		exit(EXIT_FAILURE);
	}
	printf("Insert front:\n");
	DoublyLinkedList_insertFront(list, 5);
	DoublyLinkedList_printForward(list);

	printf("Insert back:\n");
	DoublyLinkedList_insertBack(list, 7);
	DoublyLinkedList_printForward(list);

	DoublyLinkedList *new_list = malloc(sizeof(DoublyLinkedList));	
	if(new_list == NULL)
	{
		perror("Malloc failed.");
		exit(EXIT_FAILURE);
	}
	DoublyLinkedList_copy(new_list, list);
	printf("Source list is:\n");
	DoublyLinkedList_printForward(list);
	printf("New list is:\n");
	DoublyLinkedList_printForward(new_list);

	DoublyLinkedList_destroy(new_list);
	free(new_list);
	DoublyLinkedList_destroy(list);
	free(list);
}
