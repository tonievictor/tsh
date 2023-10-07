#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utilities.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment
 * variable if found, or NULL if not found.
 */

char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_len;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}

/**
 * setenv_builtin - Unset an environment variable.
 * @args: Array of command arguments (variable names).
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */

void setenv_builtin(char **args, int argc, char *command)
{
	char *existingenv;
	char **temp;
	char *buf = NULL;
	int elems = count_elements(environ), i;
	(void)command;

	if (argc != 3)
	{
		_puts("setenv: Invalid number of arguments\n");
		return;
	}
	existingenv = _getenv(args[1]);
	if (existingenv != NULL)
	{
		_strcpy(existingenv, "");
		_strcat(existingenv, args[2]);
		return;
	}
	buf = malloc((_strlen(args[1]) + _strlen(args[2]) + 2) * sizeof(char));

	_strcpy(buf, args[1]);
	_strcat(buf, "=");
	_strcat(buf, args[2]);

	temp = malloc(sizeof(char *) * (elems + 2));
	if (temp == NULL)
	{
		perror("Memory allocation failed\n");
		free(buf);
		return;
	}
	for (i = 0; i < elems; i++)
	{
		temp[i] = environ[i];
	}

	temp[elems] = buf;
	temp[elems + 1] = NULL;
	environ = temp;
}

/**
 * _unsetenv - Unset an environment variable.
 * @args: Array of command arguments (variable names).
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */

void _unsetenv(char **args, int argc, char *command __attribute__((unused)))
{
	int i, j, n;
	int variableRemoved = 0;
	char *currentEnvVar;

	if (argc != 2)
	{
		perror(args[0]);
		return;
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		currentEnvVar = environ[i];

		n = _strncmp(currentEnvVar, args[1], _strlen(args[1]));

		if (n == 0 && currentEnvVar[_strlen(args[1])] == '=')
		{

			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			variableRemoved = 1;
			break;
		}
	}

	if (!variableRemoved)
	{
		perror(args[1]);
	}
}

