#include "main.h"

/**
 * seperate_input - Separate a command string
 * into an array of tokens.
 * @command: The input command string to tokenize.
 *
 * Return: An array of tokens (strings) if
 * successful, or NULL on failure.
 */

char **seperate_input(char *command)
{
	char **tokens = NULL;
	char *token;
	int i = 0, j;
	int token_count = 5;

	token = strtok(command, " ");
	tokens = malloc(token_count * sizeof(char *));
	if (tokens == NULL)
	{
		free(command);
		command = NULL;
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		if (i >= token_count - 1)
		{
			token_count *= 2;
			tokens = realloc(tokens, token_count * sizeof(char *));
			if (tokens == NULL)
				exit(EXIT_FAILURE);
		}
		tokens[i] = token;
		if (tokens[i] == NULL)
		{
			for (j = 0; j < 30; j++)
				free(tokens[i]);
			free(tokens);
			tokens = NULL;
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

