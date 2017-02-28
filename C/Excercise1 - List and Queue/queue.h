/** Queue functions declerations: **/

/* Returns a pointer to a newly created queue. */
void * new_queue();

/* Deletes the queue it receives and its' items from the memory */
void queue_destroy(void * queue);

/* Adds the item at the end of the received queue */
void queue_add(void * queue, void * item);

/* Removes the item from the head of the received queue.
* Returns a pointer to the removed item */
void * queue_remove(void * queue);

/* Returns a pointer to the item at the head of the received queue,
* without removing it from the queue.*/
void * queue_peek(void * queue);

/* Returns the length of the received queue */
int queue_len(void * queue);