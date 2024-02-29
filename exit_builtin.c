#include "main.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * exit_builtin - Handle the 'exit' built-in command.
 * @args: Array of arguments passed to the command.
 * @argc: Number of arguments in 'args'.
 * @command: The original command string.
 *
 * This function is responsible for processing the 'exit' command.
 * If 'argc' is 1, it performs a clean exit. If 'argc' is greater than 1
 * and the argument is a positive integer, it exits with that value.
 *
 * @args and @command are freed before exiting the program.
 */

void exit_builtin(char **args, int argc, char *command) {
  int status = 0;

  (void)argc;

  if (args[1] != NULL) {
    status = _atoi(args[1]);
    if (status != 1) {
      if (envfreesignal == 1) {
        free(environ);
        free(newvariable);
      }
      free(args);
      free(command);
      args = NULL;
      command = NULL;
      exit(status);
    }
    errno = 2;
    perror("Illegal number");
    return;
  }

  if (envfreesignal == 1) {
    free(environ);
    free(newvariable);
  }
  status = errno;
  free(args);
  free(command);
  args = NULL;
  command = NULL;
  exit(status);
}
