#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Symbolic variables */
#define LIST_SIZE (sizeof(list_t))
#define NODE_SIZE (sizeof(node_t))

#define NOT_ENOUGH_MEMORY_MSG ("There isn't enough memory \
available for this action.")

/* Declaring internal functions */
static void print_list(void * list, char * name);

/* Node structure and pointer definition */
typedef struct node_t{
	void * val;
	struct node_t * next;
	struct node_t * previous;
}node_t, *node_p;

/* List structure and pointer definition */
typedef struct list_t{
	int items_count;
	long double items_sum;
	node_p head;
	node_p tail;
	conversion_delegate convert;
} list_t, *list_p;


/* Receives a conversion_function as a parameter.
Returns a pointer to a newly created list.*/
void * new_list(conversion_delegate convert)
{
	/* Allocating memory for a new list struct instance */
	list_p list = (list_p)malloc(LIST_SIZE);

	/* Handling bad memory allocation */
	if (list == NULL)
	{
		fprintf(stderr,NOT_ENOUGH_MEMORY_MSG);
		return list;
	}

	/* Initializing list fields */
	list->items_count = 0;
	list->items_sum = 0.0;
	list->head = NULL;
	list->tail = NULL;
	list->convert = convert;

	/* Returning a pointer to the new list */
	print_list(list,"INIT");
	return list;
}

/* Deletes the list it receives and its' items from the memory */
void list_destroy(void * list)
{
	/* Initializing pointers */
	node_p node = ((list_p)list)->head;
	node_p old_node = NULL;

	/* Iterating over the nodes and freeing them from memory */
	while (node != NULL)
	{
		old_node = node;
		node = node->next;
		free(old_node);
	}

	/* Freeing the list from memory*/
	free(list);
}

/* Adds the item at the end of the received list, returns a pointer the new item */
void * list_add(void * list, void * value)
{
	/* Initializing pointers */
	list_p list_pointer = (list_p)list;
	node_p tail = list_pointer->tail;

	/* Allocating memory to a new node struct instance */
	node_p new_node = (node_p)malloc(NODE_SIZE);

	/* Handling bad memory allocation */
	if (new_node == NULL)
	{
		fprintf(stderr, NOT_ENOUGH_MEMORY_MSG);
		return new_node;
	}

	/* Initializing node fields */
	new_node->val = value;
	new_node->previous = tail;
	new_node->next = NULL;

	/* Updating pointers for previously tail node and the list */
	if (tail != NULL)
	{
		tail->next = new_node;
	}
	if (list_pointer->head == NULL)
	{
		list_pointer->head = new_node;
	}
	list_pointer->tail = new_node;

	/* Updating list fields*/
	++(list_pointer->items_count);
	list_pointer->items_sum += list_pointer->convert(value);

	/* Returning a pointer to the new node */
	print_list(list, "ADD");
	return new_node;
}

/* Removes the item from the received list, returns a pointer to the next item */
void * list_remove(void * list, void * item)
{
	/* Initializing pointers */
	list_p list_pointer = (list_p)list;
	node_p del_node = (node_p)item;
	node_p next_node = NULL;

	/* Updating the next node of the deleted item's previous node.
	* If the deleted item is the head, updating the head node of the list. */
	if (del_node->previous != NULL)
	{
		del_node->previous->next = del_node->next;
	}
	else
	{
		list_pointer->head = del_node->next;
	}

	/* Updating the previous node of the deleted item's next node.
	* If the deleted item is the tail, updating the tail node of the list. */
	if (del_node->next != NULL)
	{
		del_node->next->previous = del_node->previous;
	}
	else
	{
		list_pointer->tail = del_node->previous;
	}

	/* Updating list fields*/
	--(list_pointer->items_count);
	list_pointer->items_sum -= list_pointer->convert(del_node->val);

	/* Keeping an instance of the next node and freeing the deleted node from memory*/
	next_node = del_node->next;
	free(del_node);

	/* Returning the next node after the deleted node */
	print_list(list,"REMOVE");
	return next_node;
}

/* Returns the length of the received list */
int list_len(void * list)
{
	return ((list_p)list)->items_count;
}

/* Returns a pointer to the first item of the received list */
void * get_first(void * list)
{
	return ((list_p)list)->head;
}

/* Returns a pointer to the last item of the received list */
void * get_last(void * list)
{
	return ((list_p)list)->tail;
}

/* Returns a pointer to the next item after the received item */
void * get_next(void * item)
{
	return ((node_p)item)->next;
}

/* Returns a pointer to the previous item before the received item */
void * get_previous(void * item)
{
	return ((node_p)item)->previous;
}

/* Returns a pointer to the value of the item it receives */
void * get_value(void * item)
{
	return ((node_p)item)->val;
}

/* Returns the average of the items in the list it receives */
double get_average(void * list)
{
	return ((list_p)list)->items_sum / ((list_p)list)->items_count;
}

/* Prints the status of the list */
static void print_list(void * list,char * name)
{
	list_p l = (list_p)list;
	node_p node = l->head;
	if (DBG_LVL)
	{
		fprintf(stdout, "******** %s *********\n", name);
		if (DBG_LVL > 1)
		{
			fprintf(stdout, "sum : %0.1f, count %d\n", l->items_sum, l->items_count);
			while (node != NULL)
			{
				switch (DBG_TYPE)
				{
				case DBG_INT:
					fprintf(stdout, "%02d, ", l->convert(node->val));
					break;
				case DBG_DOUBLE:
					printf("%02.2f, ", l->convert(node->val));
					break;
				}
				node = node->next;
			}
		}
		else
		{
			fprintf(stdout, "Done.");
		}
		fprintf(stdout, "\n\n");
	}
}