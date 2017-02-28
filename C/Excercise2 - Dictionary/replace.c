#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

/* Errors */
#define WRONG_USAGE (1)
#define WRONG_USAGE_MSG ("Usage: replace [text-file] \
[replacement-file] [dictionary-file]")
#define MEMORY_ERROR (2)
#define MEMORY_ERROR_MSG ("There isn't enough memory \
available for this action.")
#define WRONG_FILE (3)

/* The format for the dictionary file is:
'Word1:synonym1 synonym2 synonym3 synonym4\n
Word2:synonym1 synonym2 synonym3 synonym4\n
Word3...' */
int main(int argc, void * argv[])
{
	/* Intializing pointers */
	FILE * text_file = NULL;
	FILE * dic_file = NULL;
	FILE * new_file = NULL;
	void * dictionary = NULL;
	char * buffer = malloc(sizeof(char)*(WORD_LENGTH_LIMIT+1));
	char * replacement = malloc(sizeof(char)*(WORD_LENGTH_LIMIT + 1));

	/* Handling memory allocation errors */
	if (buffer == NULL || replacement == NULL)
	{
		fprintf(stderr, MEMORY_ERROR_MSG);
		return MEMORY_ERROR;
	}
		
	/* Handling wrong usage errors */
	if (argc != 4)
	{
		fprintf(stderr, WRONG_USAGE_MSG);
		return WRONG_USAGE;
	}

	/* Opening and parsing the dictionary file.
	Handling file and format errors. */
	dic_file = fopen(argv[3], "r");
	if (dic_file == NULL)
	{
		fprintf(stderr, "Couldn't open the dictionary file.");
		return WRONG_FILE;
	}
	dictionary = init_dictionary(dic_file);
	fclose(dic_file);
	if (dictionary == NULL)
	{
		return WRONG_FILE;
	}

	/* Opening/creating the text file and the result file.
	Handling file errors. */
	text_file = fopen(argv[1], "r");
	if (text_file == NULL)
	{
		fprintf(stderr, "Couldn't open the text file.");
		return WRONG_FILE;
	}
	new_file = fopen(argv[2], "w");
	if (new_file == NULL)
	{
		fprintf(stderr, "Couldn't open/create the text file.");
		return WRONG_FILE;
	}

	/* Iterating over the words in the text file. 
	Replacing them if they are found in the dictionary. */
	while (fscanf(text_file, "%s", buffer) != EOF)
	{
		replacement = get_next_value_for_key(dictionary, buffer);
		if (replacement != NULL)
		{
			fprintf(new_file, "%s ", replacement);
		}
		else
		{
			fprintf(new_file, "%s ", buffer);
		}
	}

	/* Freeing memory and closing files */
	dictionary_destroy(dictionary);
	fclose(text_file);
	fclose(new_file);
	free(buffer);
	free(replacement);

	fprintf(stdout, "\nSuccessfully replaced words in %s with synonyms from %s to new file %s.\n",argv[1],argv[3],argv[2]);
	return 0;
}