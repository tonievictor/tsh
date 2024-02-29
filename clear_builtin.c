#include "main.h"
#include "utilities.h"

/**
 * clear_builtin - clears the terminal screen.
 * @args: Array of command arguments.
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */
void clear_builtin(char **args, int argc, char *command) {
  (void)argc;
  (void)command;
  (void)args;

  _puts("\033c");
}
