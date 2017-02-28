/** List debugging **/

enum DBG_LVL_VALUE {
	NONE,
	INFO,
	DEBUG
};
#define DBG_LVL (DEBUG) /* 0 - 2 */
#define DBG_INT ('i')
#define DBG_DOUBLE ('d')
#define DBG_TYPE (DBG_INT)

/** Type declerations: **/

/*A conversion_delegate receives a void pointer to a value in the list,
and returns its' correctly casted double value.
This is used for correctly calculating the average of the items in the list. */
typedef double(*conversion_delegate)(void * value);


/** List functions declerations: **/

/* Receives a conversion_function as a parameter.
Returns a pointer to a newly created list.*/
void * new_list(conversion_delegate convert);

/* Deletes the list it receives and its' items from the memory */
void list_destroy(void * list);

/* Adds the item at the end of the received list, returns a pointer the new item */
void * list_add(void * list, void * value);

/* Removes the item from the received list, returns a pointer to the next item */
void * list_remove(void * list, void * item);

/* Returns the length of the received list */
int list_len(void * list);

/* Returns a pointer to the first item of the received list */
void * get_first(void * list);

/* Returns a pointer to the last item of the received list */
void * get_last(void * list);

/* Returns a pointer to the next item after the received item */
void * get_next(void * item);

/* Returns a pointer to the previous item before the received item */
void * get_previous(void * item);

/* Returns a pointer to the value of the item it receives */
void * get_value(void * item);

/* Returns the average of the items in the list it receives */
double get_average(void * list);
