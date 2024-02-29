#include "main.h"
#include "string.h"
#include "utilities.h"

/**
 * execute_builtin - Execute a built-in command.
 * @args: Array of command arguments.
 * @command: The built-in command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */

int execute_builtin(char **args, char *command) {
  unsigned long int i;
  int argc = count_elements(args);
  unsigned long int size = 0;
  BuiltInCommand builtins[] = {{"exit", exit_builtin},
                               {"env", env_builtin},
                               {"setenv", setenv_builtin},
                               {"unsetenv", _unsetenv},
                               {"clear", clear_builtin},
                               {"cd", cd_builtin},
                               {NULL, NULL}};

  while (builtins[size].name != NULL)
    size++;
  if (argc <= 0)
    return (1);
  for (i = 0; i < size; i++) {
    if (_strlen(args[0]) == _strlen(builtins[i].name)) {
      if (_strncmp(args[0], builtins[i].name, _strlen(builtins[i].name)) == 0) {
        builtins[i].function(args, argc, command);
        return (0);
      }
    }
  }
  return (1);
}
