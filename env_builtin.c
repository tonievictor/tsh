#include "main.h"
#include "utilities.h"

/**
 * env_builtin - Execute the 'env' built-in command.
 * @args: Array of command arguments.
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */

void env_builtin(char **args, int argc, char *command) {
  char **env = environ;
  char *current;

  (void)command;

  if (argc > 1) {
    perror(args[0]);
    return;
  }

  while (*env != NULL) {
    current = *env;
    while (*current != '\0') {
      _putchar(*current);
      current++;
    }
    _putchar('\n');
    env++;
  }
}
