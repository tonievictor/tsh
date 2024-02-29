#include "main.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment
 * variable if found, or NULL if not found.
 */

char *newvariable;
int envfreesignal = 0;

char *_getenv(const char *name) {
  char **env = environ;
  size_t name_len;

  if (name == NULL || environ == NULL)
    return (NULL);

  name_len = _strlen(name);

  for (env = environ; *env != NULL; env++) {
    if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=') {
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

void setenv_builtin(char **args, int argc, char *command) {
  char **tempenv;
  size_t tempsize;
  unsigned long arglength;
  size_t i, j;

  (void)command;

  if (argc != 3) {
    _puts("setenv: Invalid number of arguments\n");
    return;
  }

  i = count_elements(environ);
  arglength = strlen(args[1]) + strlen(args[2]) + 2;
  tempenv = malloc((i + 2) * sizeof(char *));
  newvariable = malloc(arglength * sizeof(char));

  if (tempenv == NULL || newvariable == NULL) {
    _puts("setenv: Failed to allocate memory\n");
    return;
  }
  envfreesignal = 1;
  tempsize = 0;
  _strcpy(newvariable, args[1]);
  _strcat(newvariable, "=");
  _strcat(newvariable, args[2]);

  for (j = 0; environ[j] != NULL; j++) {
    tempenv[j] = environ[j];
    tempsize++;
  }

  tempenv[tempsize] = newvariable;
  tempenv[tempsize + 1] = NULL;
  environ = tempenv;

  if (envargssignal == 1) {
    free(args[2]);
    free(args);
  }
}

/**
 * _unsetenv - Unset an environment variable.
 * @args: Array of command arguments (variable names).
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */

void _unsetenv(char **args, int argc, char *command) {
  int i, j, n;
  int variableRemoved = 0;
  char *currentEnvVar;

  (void)command;

  if (argc != 2) {
    _puts("unsetenv: Invalid number of arguments\n");
    return;
  }

  for (i = 0; environ[i] != NULL; i++) {
    currentEnvVar = environ[i];

    n = _strncmp(currentEnvVar, args[1], _strlen(args[1]));

    if (n == 0 && currentEnvVar[_strlen(args[1])] == '=') {
      for (j = i; environ[j] != NULL; j++) {
        environ[j] = environ[j + 1];
      }
      variableRemoved = 1;
      break;
    }
  }

  if (variableRemoved == 0) {
    _puts("unsetenv: Environment variable provided does not exist\n");
  }
}
