#include"doubly_linked_list.h"

void DoublyLinkedList_init(DoublyLinkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

Node* creat(int value)
{
	Node *node = malloc(sizeof(Node));
	if(node == NULL)
	{
		return NULL;
	}
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void DoublyLinkedList_destroy(DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	Node *node = list->head;
	Node *res_node = node;
	while(node)
	{
		res_node = node;
		node = node->next;
		free(res_node);
	}
	DoublyLinkedList_init(list);
}

void DoublyLinkedList_copy(DoublyLinkedList *dest, const DoublyLinkedList *src)
{
	if(dest == NULL || src == NULL)
	{
		return;
	}
	DoublyLinkedList_init(dest);
	if(src->size == 0)
	{
		return;
	}
	
	Node* new_node = NULL;
	Node *prev_node = src->head;
	Node *current_node = src->head;
	while(current_node != NULL)
	{
		new_node = malloc(sizeof(Node));
		new_node->value = current_node->value;
		if(dest->size == 0)
		{
			new_node->prev = NULL;
			new_node->next = NULL;	
			dest->head = new_node;
		}
		else
		{
			prev_node->next = new_node;
		}
		dest->size++;
		prev_node = new_node;
		current_node = current_node->next;
	}
	dest->tail = new_node;
}

void DoublyLinkedList_insertFront(DoublyLinkedList *list, int value)
{
	if(list == NULL)
	{
		return;
	}
	Node *node = creat(value);
	if(node == NULL)
	{
		return;
	}
	if(list->size == 0)
	{
		list->head = node;
		list->tail = node;
		list->size++;
		return;
	}
	node->next = list->head;
	list->head->prev = node;
	list->head = node;
	list->size++;
}

void DoublyLinkedList_insertBack(DoublyLinkedList *list, int value)
{
	if(list == NULL)
	{
		return;
	}
	Node *node = creat(value);
	if(node == NULL)
	{
		return;
	}
	if(list->size == 0)
	{
		list->head = node;
		list->tail = node;
		list->size++;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
		list->size++;
	}
	return;
}

void DoublyLinkedList_insertAfter(DoublyLinkedList *list, Node *node, int value)
{
	if(list == NULL || node == NULL)
	{
		return;
	}
	if(node == list->tail)
	{
		DoublyLinkedList_insertBack(list, value);
		return;
	}
	Node *new_node = creat(value);
	if(new_node == NULL)
	{
		return;
	}
	new_node->next = node->next;
	new_node->prev = node;
	node->next->prev = new_node;
	node->next = new_node;
	list->size++;
}

void DoublyLinkedList_insert(DoublyLinkedList *list, int position, int value)
{
	if((list == NULL) || (position < 0) || (position > list->size))
	{
		return;
	}
	if(position == list->size)
	{
		DoublyLinkedList_insertBack(list, value);
		return;
	}
	Node *node = list->head;
	while(node != NULL && position > 0)
	{
		node= node->next;
		position--;
	}
	DoublyLinkedList_insertBefore(list, node, value);
	return;
}

void DoublyLinkedList_insertBefore(DoublyLinkedList *list, Node *node, int value)
{
	if(list == NULL || node == NULL)
	{
		return;
	}
	if(node == list->head)
	{
		DoublyLinkedList_insertFront(list, value);
		return;
	}
	Node *new_node = creat(value);
	if(new_node == NULL)
	{
		printf("insertation failed.\n");
		return;
	}	
	node->prev->next = new_node;
	new_node->prev = node->prev;
	new_node->next = node;
	node->prev = new_node;
	list->size++;
	return;
}

void DoublyLinkedList_removeFront(DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	if(list->size == 0)
	{
		return;
	}
	if(list->size == 1)
	{
		free(list->head);
		DoublyLinkedList_init(list);
		return;
	}
	Node *res = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	list->size--;
	free(res);
}

void DoublyLinkedList_removeBack(DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	if(list->size == 1)
	{
		free(list->head);
		DoublyLinkedList_init(list);
		return;
	}
	Node *res = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;
	list->size--;
	free(res);
}

void DoublyLinkedList_removeNode(DoublyLinkedList *list, Node *node)
{
	if(list == NULL || node == NULL)
	{
		return;
	}
	if(node == list->head)
	{
		DoublyLinkedList_removeFront(list);
		return;
	}
	if(node == list->tail)
	{
		DoublyLinkedList_removeBack(list);
		return;
	}
	Node *tmp = list->head;
	while(tmp != NULL)
	{
		if(tmp != node)
		{
			tmp = tmp->next;
		}
		else
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			list->size--;
			return;
		}
	}
	printf("Not found\n");
	return;
}

Node* DoublyLinkedList_search(DoublyLinkedList *list, int value)
{
	if(list == NULL)
	{
		return NULL;
	}
	Node *node = list->head;
	while(node)
	{
		if(node->value == value)
		{
			return node;
		}
		else
		{
			node = node->next;
		}
	}
	return NULL;
}

int DoublyLinkedList_getSize(const DoublyLinkedList *list)
{	
	if(list == NULL)
	{
		return -1;
	}

	return list->size;
}

bool DoublyLinkedList_isEmpty(const DoublyLinkedList *list)
{	
	if(list == NULL)
	{
		return true;
	}

	return list->size == 0;
}

void DoublyLinkedList_printForward(const DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	if(list->size == 0)
	{
		printf("Empty list.\n");
	}
	Node *node = list->head;
	while(node != NULL)
	{
		printf("%5d", node->value);
		node = node->next;
	}
	printf("\n");
	return;
}

void DoublyLinkedList_printBackward(const DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	if(list->size == 0)
	{
		printf("Empty list.\n");
	}
	Node *node = list->tail;
	while(node != NULL)
	{
		printf("%5d", node->value);
		node = node->prev;
	}
	printf("\n");
	return;
}

void DoublyLinkedList_reverse(DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	if(list->size == 1)
	{
		return;
	}
	Node *node = list->head;
	Node *tmp = node;
	while(node)
	{
		tmp = node->next;
		node->next = node->prev;
		node->prev = tmp;
		node = node->prev;
	}
	tmp = list->head;
	list->head = list->tail;
	list->tail = tmp;
	return;
}

void DoublyLinkedList_clear(DoublyLinkedList *list)
{
	if(list == NULL)
	{
		return;
	}
	Node *node = list->head;
	while(node)
	{
		node->value = 0;
		node = node->next;
	}
}
