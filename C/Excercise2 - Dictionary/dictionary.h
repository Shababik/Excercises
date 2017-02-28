#include <stdio.h>

/* Limits */

#define WORDS_LIMIT (5)
#define WORD_LENGTH_LIMIT (15)

/** Dictionary functions declerations: **/

/* Receives a dictionary file as a parameter.
Returns a pointer to a newly created dictionary. 
The format for the dictionary file is:
'Word1:synonym1 synonym2 synonym3 synonym4\n
Word2:synonym1 synonym2 synonym3 synonym4\n
Word3...' */
void * init_dictionary(FILE * dictionary_file);

/* Deletes the dictionary it receives and its' items from the memory */
void dictionary_destroy(void * dic);

/* Returns the next synonym value for the key, if it exists in the dictionary.
Otherwise, returns NULL. */
char * get_next_value_for_key(void * dic, char * key);