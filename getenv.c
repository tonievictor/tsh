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
	(void)command;

	if (argc != 3)
	{
		_puts("setenv: Invalid number of arguments\n");
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		_puts("Failed to set environment variable\n");
	}
}

/**
 * _unsetenv - Unset an environment variable.
 * @args: Array of command arguments (variable names).
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */

void _unsetenv(char **args, int argc, char *command)
{
	int i, j, n;
	int variableRemoved = 0;
	char *currentEnvVar;

	(void)command;

	if (argc != 2)
	{
		_puts("unsetenv: Invalid number of arguments\n");
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
		_puts("unsetenv: Environment variable provided does not exist\n");
	}
}
