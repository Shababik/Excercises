#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Limits and sizes */
#define BOARD_LENGTH (10)
#define BOARD_SIZE (sizeof(char)*(BOARD_LENGTH * (2+BOARD_LENGTH)))

/* Errors */
#define WRONG_USAGE (1)
#define WRONG_FORMAT (2)

/* Declaraing variables */
char alive_char;
char dead_char;
int lives;
unsigned char board[BOARD_LENGTH][BOARD_LENGTH+2];

/* Declaring functions */
int count_neighbors(int row, int col);
int is_alive(int row, int col);
void play_round();
void print_board();
int parse_board(FILE * board_file);


/* Board file format: (10x10)
'---------\n
----VVV---\n
----------\n...'
Alive/dead chars are per user choice. */
int main(int argc, char * argv[])
{
	FILE * board_file = NULL;
	int i = 0;

	/* Intializing varaibles from passed arguments.
	Handling wrong usage errors. */
	if (argc != 5)
	{
		fprintf(stderr, "Usage: life [%dx%d board-file] [alive-char] [dead-char] [lives]", BOARD_LENGTH, BOARD_LENGTH);
		return WRONG_USAGE;
	}

	alive_char = argv[2][0];
	dead_char = argv[3][0];
	if (sscanf(argv[4], "%d", &lives) == 0)
	{
		fprintf(stderr, "Usage: life [%dx%d board-file] [alive-char] [dead-char] [lives]", BOARD_LENGTH, BOARD_LENGTH);
		return WRONG_USAGE;
	}

	/* Opening board file, parsing it and closing the file */
	board_file = fopen(argv[1], "r");
	if (board_file == NULL || parse_board(board_file) == WRONG_FORMAT)
	{
		fprintf(stderr, "The format of the board file is wrong.");
		return WRONG_FORMAT;
	}
	fclose(board_file);

	/* Running life algorithm for the amount of lives specified. */
	print_board(-1);
	for (i = 0; i < lives; ++i)
	{
		play_round();
		print_board(i);
	}
	return 0;
}

/* Returns the amount of 'alive' chars surrounding char at [row,col] */
int count_neighbors(int row, int col)
{
	/* Initializing variables */
	signed int i = 0, j = 0;
	int count = 0;
	int real_row, real_col;

	/* Iterating over 8 chars surrounding char at [row,col],
	and counting 'alive' chars. When reaching a border,
	the board continues from the opposite side. */
	for (i = row - 1; i <= row + 1; ++i)
	{
		for (j = col - 1; j <= col + 1; ++j)
		{
			real_row = i < 0 ? i % BOARD_LENGTH + BOARD_LENGTH : i % BOARD_LENGTH;
			real_col = j < 0 ? j % BOARD_LENGTH + BOARD_LENGTH : j % BOARD_LENGTH;
			if ((real_row != row || real_col != col)
				&& board[real_row][real_col] == alive_char)
			{
				++count;
			}
		}
	}
	return count;
}

/* Checks whether a char at [row,col] will be 'alive' in the next life */
int is_alive(int row, int col)
{
	/* Initializing variables */
	int alive_neighbors = count_neighbors(row, col);
	char unit = board[row][col];

	/* Returning the condition for being 'alive' depending 
	on the current status of the unit - alive/dead */
	if (unit == alive_char)
	{
		return alive_neighbors >= 2 && alive_neighbors <= 3;
	}
	else
	{
		return alive_neighbors == 3;
	}
}

/* Runs the life algorithm for a single lifetime */
void play_round()
{
	/* Initializing variables */
	int i = 0, j = 0;
	unsigned char new_board[BOARD_LENGTH][BOARD_LENGTH + 2];

	/* Iterating over the chars on the board, 
	determining the status of each char in the next life. */
	for (i = 0; i < BOARD_LENGTH; ++i)
	{
		for (j = 0; j < BOARD_LENGTH+1; ++j)
		{
			if (j < BOARD_LENGTH)
			{
				new_board[i][j] = is_alive(i, j) ? alive_char : dead_char;
				continue;
			}
			new_board[i][j] = '\n';
			new_board[i][j+1] = '\0';
		}
	}
	/* Copying the new board */
	for (int i = 0; i < BOARD_LENGTH; ++i)
	{
		strcpy(board[i], new_board[i]);
	}
}

/* Prints the current board status */
void print_board(int life)
{
	fprintf(stdout, "***** LIFE %d: *****\n", life + 1);
	int i = 0, j = 0;
	char * q = malloc(BOARD_SIZE);
	char * p = q;
	for (i = 0; i < BOARD_LENGTH; ++i)
	{
		for (j = 0; j < BOARD_LENGTH; ++j)
		{
			*p = board[i][j];
			++p;
		}
		*p = '\n';
		++p;
	}
	*p = '\0';
	fprintf(stdout, "%s\n\n", q);
	free(q);
}

/* Parses the board file into variable board */
int parse_board(FILE * board_file)
{
	/* Initializing variables*/
	char * p = board;
	int i = 0;
	int next_char = 0;

	/* Iterating over chars in file */
	while (i < BOARD_SIZE/sizeof(char) 
		&& ((next_char = fgetc(board_file)) != EOF))
	{
		/* Skipping space chars unless they are in the correct positions,
		in which case they are copied to the board. */
		if (isspace(next_char))
		{
			if ((i - BOARD_LENGTH) % (BOARD_LENGTH + 2) == 0)
			{
				*(p + i) = '\n';
				*(p + ++i) = '\0';
				++i;
			}
			continue;
		}
		/* Handling problems with file format */
		else if ((i - BOARD_LENGTH) % (BOARD_LENGTH + 2) == 0)
		{
			return WRONG_FORMAT;
		}

		/* Copying the current char to the board */
		*(p + i) = next_char;
		++i;
	}
	/* Handling problems with file format */
	if (i < BOARD_SIZE / sizeof(char) - 2 || (!isspace(next_char) && next_char != EOF))
	{
		return WRONG_FORMAT;
	}
	if (!isspace(next_char))
	{
		*(p + i) = '\0';
	}
	return 0;
}