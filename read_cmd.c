#include "main.h"
#include <stdlib.h>

/**
 * read_command - Reads a line of user input as a command.
 *
 * Return: A pointer to the input line if successful.
 * or NULL if an error occurs or the end of input is reached.
 */

char *read_command(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t read;

	read = getline(&line, &length, stdin);

	if (read == -1)
	{
		free(line);
		line = NULL;
		return (line);
	}
	line[read - 1] = '\0';
	return (line);
}

