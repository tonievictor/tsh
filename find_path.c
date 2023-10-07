#include "main.h"
#include "utilities.h"
#include <stdlib.h>

/**
 * find_command_in_path - Find a command in the given path.
 * @path: The search path to look for the command.
 * @command: The command to find.
 *
 * Return: A pointer to the full path of the
 * command if found, or NULL if not found.
 */

char *find_command_in_path(char *path, char *command)
{
	char *full_path = NULL;
	char *path_copy = _strdup(path);
	char *token;
	size_t len;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		len = _strlen(token) + 1 + _strlen(command) + 1;
		full_path = (char *)malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);

	return (NULL);
}

