#include "main.h"
#include "utilities.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * runpathcmd - function to run a command
 * if the path is provided
 * @command: user input
 * @tokens:  a pointer to an array of commands
 * Ideally tokens[0] is the command to run
 * Return: the status
 */

int runpathcmd(char *command, char **tokens) {
  pid_t child_pid;
  int status_code = 0;

  child_pid = fork();
  if (child_pid < 0) {
    perror("fork");
    return (1);
  }
  if (child_pid == -1) {
    perror("fork");
    free(command);
    free(tokens);
    command = NULL;
    tokens = NULL;
  }
  if (child_pid == 0) {
    if (execve(tokens[0], tokens, NULL) == -1) {
      perror(command);
      freecommandspath(command, tokens);
      exit(EXIT_FAILURE);
    }
  } else {
    freecommandspath(command, tokens);
    do {
      waitpid(child_pid, &status_code, WUNTRACED);
    } while (!WIFEXITED(status_code) && !WIFSIGNALED(status_code));
  }

  return (status_code);
}

/**
 * freecommandspath - Free memory allocated for
 * command, tokens, and directory.
 * @command: The command string to free.
 * @tokens: The array of tokens to free.
 */

void freecommandspath(char *command, char **tokens) {
  free(command);
  free(tokens);
  command = NULL;
  tokens = NULL;
}

/**
 * runpathlesscmd - function to run pathless command.
 *
 * @command: A pointer to a character array representing the command.
 * @tokens: tokens An array of pointers to character arrays
 *
 * Return: void
 *
 */

int runpathlesscmd(char *command, char **tokens) {
  pid_t child_pid;
  char *path = getenv("PATH");
  char *directory = find_command_in_path(path, tokens[0]);
  int status_code = 0;

  if (directory == NULL) {
    perror(command);
    freecommands(command, tokens, directory);
  } else {
    child_pid = fork();
    if (child_pid < 0) {
      perror("fork");
      return (1);
    }
    if (child_pid == -1) {
      perror("fork");
      freecommands(command, tokens, directory);
    } else if (child_pid == 0) {
      exec_and_free(command, tokens, directory);
    } else {
      freecommands(command, tokens, directory);
      do {
        waitpid(child_pid, &status_code, WUNTRACED);
      } while (!WIFEXITED(status_code) && !WIFSIGNALED(status_code));
    }
  }
  return (status_code);
}

/**
 * freecommands - Free memory allocated for
 * command, tokens, and directory.
 * @command: The command string to free.
 * @tokens: The array of tokens to free.
 * @directory: the directory where the excutable file is
 */

void freecommands(char *command, char **tokens, char *directory) {
  free(command);
  free(tokens);
  free(directory);
}

/**
 * exec_and_free - function to execute pathless commands
 * did this just to remove functionality
 * @command: The command string to free.
 * @tokens: The array of tokens to free.
 * @directory: the directory where the excutable file is
 */

void exec_and_free(char *command, char **tokens, char *directory) {
  if (execve(directory, tokens, NULL) == -1) {

    perror(command);
    freecommands(command, tokens, directory);
    exit(EXIT_FAILURE);
  }
}
