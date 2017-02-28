#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "queue.h"
#include "dictionary.h"

/* Errors */
#define CORRUPTED_DICTIONARY (NULL)
#define CORRUPTED_DICTIONARY_MSG ("The dictionary received is nullified.")
#define WRONG_FORMAT (1)
#define WRONG_FORMAT_MSG ("The format of the dictionary is wrong.")

/* Byte sizes */
#define DICTIONARY_SIZE (sizeof(dictionary_t))
#define WORD_QUEUE_SIZE (sizeof(words_t))
#define DICTIONARY_LINE_SIZE (sizeof(char)*((WORDS_LIMIT + 1)*(WORD_LENGTH_LIMIT + 1) + 2))

/* Dictionary structure and pointer definition */
typedef struct dictionary {
	void * words_list;
} dictionary_t, *dictionary_p;

/* Dictionary key-values queue structure and pointer definition */
typedef struct words_queue {
	void * queue;
	char key[WORD_LENGTH_LIMIT + 1];
	char values[WORDS_LIMIT][WORD_LENGTH_LIMIT + 1];
	int usage_count;
} words_t, *words_p;

/* Declaring internal functions */
static double delegate(void * value);
static int parse_dictionary(dictionary_p dic, FILE * dictionary);


/* Receives a dictionary file as a parameter.
Returns a pointer to a newly created dictionary.
The format for the dictionary file is:
'Word1:synonym1 synonym2 synonym3 synonym4\n
Word2:synonym1 synonym2 synonym3 synonym4\n
Word3...' */
void * init_dictionary(FILE * dictionary_file)
{
	dictionary_p dic;

	/* Handling bad dictionary_file */
	if (dictionary_file == NULL)
	{
		fprintf(stderr, CORRUPTED_DICTIONARY_MSG);
		return CORRUPTED_DICTIONARY;
	}

	/* Allocating memory for a new dictionary struct instance.
	Instantiating list variable for dictionary.*/
	dic = (dictionary_p)malloc(DICTIONARY_SIZE);
	dic->words_list = new_list(delegate);

	/* Parsing the dictionary file into the dictionary struct.
	Checking for illegal return value. */
	if (parse_dictionary(dic, dictionary_file) == WRONG_FORMAT)
	{
		dictionary_destroy(dic);
		fprintf(stderr, WRONG_FORMAT_MSG);
		return CORRUPTED_DICTIONARY;
	}

	/* Returning a pointer to the parsed dictionary struct */
	return dic;
}

/* Deletes the dictionary it receives and its' items from the memory */
void dictionary_destroy(void * dic)
{
	/* Initializing pointers */
	dictionary_p dict_p = (dictionary_p)dic;
	void * node = get_first(dict_p->words_list);
	words_p words_queue = NULL;

	/* Iterating over the nodes and freeing their words_p values from memory */
	while (node != NULL)
	{
		words_queue = get_value(node);
		queue_destroy(words_queue->queue);
		free(words_queue);
		node = get_next(node);
	}

	/* Freeing the dictionary and its' content from memory */
	free(dict_p->words_list);
	free(dict_p);
}

/* Returns the next synonym value for the key, if it exists in the dictionary.
Otherwise, returns NULL. */
char * get_next_value_for_key(void * dic, char * key)
{
	/* Initializing variables and pointers */
	words_p words_queue = NULL;
	void * node = get_first(((dictionary_p)dic)->words_list);
	int len = 0;

	/* Iterating over the words_p values in the dictionary's list */
	while (node != NULL)
	{
		words_queue = (words_p)(get_value(node));

		/* Getting a value from the queue if the key received
		matches one of the keys in the dictionary */
		if (strcmp(key, words_queue->key)==0)
		{
			++(words_queue->usage_count);
			len = queue_len(words_queue->queue);

			/* Using the key itself as a synonym per queue iteration */
			if ((words_queue->usage_count-1) % (len + 1) == 0)
			{
				return words_queue->key;
			}

			/* The synonym is removed and added at the end of the queue */
			char * next_val = queue_peek(words_queue->queue);
			queue_add(words_queue->queue, queue_remove(words_queue->queue));
			
			return next_val;
		}
		node = get_next(node);
	}
	/* Returning NULL if the key was not found in the dictionary */
	return NULL;
}

/* Parses the dictionary file into the dictionary_p pointer it receives */
static int parse_dictionary(dictionary_p dic, FILE * dictionary)
{
	/* Initializing pointers and variables*/
	char * r_buffer;
	char * r_pointer;
	char * w_pointer;
	int next_char;
	int i = 0;
	words_p words_queue = NULL;
	 
	/* Allocating memory for a key-values set in the dictionary file */
	r_buffer = malloc(DICTIONARY_LINE_SIZE);
	
	/* Iterating over the lines in the dictionary file */
	while (fgets(r_buffer, DICTIONARY_LINE_SIZE, dictionary) != NULL)
	{
		r_pointer = r_buffer - 1;

		/* Allocating memory for a new words_t entry in the dictionary.
		Initializing the words_p variables. */
		words_queue = (words_p)malloc(WORD_QUEUE_SIZE);
		words_queue->usage_count = 0;
		words_queue->queue = new_queue();
		for (i = 0; i < WORDS_LIMIT; ++i)
		{
			strcpy(words_queue->values[i], "");
		}

		w_pointer = words_queue->key;

		/* Parsing the key word into the words_p entry */
		while (w_pointer < (words_queue->key + WORD_LENGTH_LIMIT)
			&& isalpha(next_char = *(++r_pointer)))
		{
			*w_pointer = next_char;
			++w_pointer;
		}
		/* Handling format errors */
		if (next_char != ':')
		{
			return WRONG_FORMAT;
		}
		*w_pointer = '\0';

		i = 0;
		w_pointer = words_queue->values[i];
		next_char = *(++r_pointer);

		/* Iterating over the values */
		while (next_char != '\0' && !isspace(next_char) && i < WORDS_LIMIT)
		{
			--r_pointer;
			/* Parsing each word value into the words_p entry */
			while (w_pointer < words_queue->values[i] + WORD_LENGTH_LIMIT && isalpha(next_char = *(++r_pointer)))
			{
				*w_pointer = next_char;
				++w_pointer;
			}
			/* Handling format errors */
			if (!isspace(next_char) && next_char!='\0')
			{
				return WRONG_FORMAT;
			}
			*w_pointer = '\0';
			++i;
			w_pointer = words_queue->values[i];
			next_char = *(++r_pointer);
		}

		i = 0;
		/* Adding the parsed values to the words_p entry queue */
		for (i = 0; i < WORDS_LIMIT; ++i)
		{
			if (strcmp(words_queue->values[i],"")!=0)
			{
				queue_add(words_queue->queue, &(words_queue->values[i]));
			}
			else break;
		}
		/* Adding the words_p entry to the dictionary list*/
		list_add(dic->words_list, words_queue);

	}
	free(r_buffer);
	return 0;
}

/* A filler delegate used to initialize the dictionary's list */
static double delegate(void * value)
{
	return 1.0;
}

