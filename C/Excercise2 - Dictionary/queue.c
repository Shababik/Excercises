#include <stdio.h>
#include "list.h"

/* Declaring internal functions */
static double delegate(void * value);

/* Returns a pointer to a newly created queue. */
void * new_queue()
{
	/* Allocating memory to a new queue instance (using list) */
	void * queue = new_list(delegate);
	
	/* Handling bad memory allocation */
	if (queue == NULL)
	{
		return queue;
	}

	/* Returning a pointer to the new queue */
	return queue;
}

/* Deletes the queue it receives and its' items from the memory */
void queue_destroy (void * queue)
{
	list_destroy(queue);
}

/* Adds the item at the end of the received queue */
void queue_add(void * queue, void * item)
{
	list_add(queue, item);
}

/* Removes the item from the head of the received queue.
* Returns a pointer to the removed item */
void * queue_remove(void * queue)
{
	/* Retrieving pointers to the first item and its' value */
	void * first_item = get_first(queue);
	void * ret_value = get_value(first_item);

	/* Removing the item and returning its' value */
	list_remove(queue, first_item);
	return ret_value;
}

/* Returns a pointer to the item at the head of the received queue,
* without removing it from the queue.*/
void * queue_peek(void * queue)
{
	return get_value(get_first(queue));
}

/* Returns the length of the received queue */
int queue_len(void * queue)
{
	return list_len(queue);
}

/* An internal delegate for list initialization */
static double delegate(void * value)
{
	/*return *(double*)value;*/
	return 1.0;
}