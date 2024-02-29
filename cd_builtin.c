#include "main.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int envargssignal = 0;
/**
 * cd_builtin - changes the current working directory of the shell
 * @args: Array of command arguments.
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */
void cd_builtin(char **args, int argc, char *command) {
  char *directory = args[1];
  int ret;
  char *full_path;
  char **env_args;

  (void)argc;
  (void)command;

  /* If no argument is provided or argument is ~, change to HOME directory */
  if (argc == 1 || _strcmp(args[1], "~") == 0) {
    directory = _getenv("HOME");
    if (directory == NULL) {
      perror("cd: No HOME directory found\n");
      return;
    }
  }

  ret = chdir(directory);
  if (ret == -1)
    perror("cd");

  full_path = getcwd(NULL, 0);
  if (full_path == NULL) {
    perror("getcwd");
    return;
  }

  env_args = malloc(3 * sizeof(char *));
  if (env_args == NULL) {
    perror("cd");
  }

  env_args[0] = "setenv";
  env_args[1] = "PWD";
  env_args[2] = full_path;

  envargssignal = 1;
  setenv_builtin(env_args, 3, "");
}
