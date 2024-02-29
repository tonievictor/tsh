#ifndef MAIN_H
#define MAIN_H

#include "unistd.h"
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;
extern char *newvariable;
extern int envfreesignal;
extern int envargssignal;

#define MAX_PATH_LENGTH 1024

/** Print prompt**/
void print_dollar(void);
char *read_command(void);
void remove_comments(char *command);

char **seperate_input(char *command);
char *find_command_in_path(char *path, char *command);
char *_getenv(const char *name);
int runpathcmd(char *command, char **tokens);
int runpathlesscmd(char *command, char **tokens);
int _stripstr(char *command);
int execute_command(char *command, char **tokens_array);
void freecommandspath(char *command, char **tokens);
void exec_and_free(char *command, char **tokens, char *directory);
/**
 * struct builtin - Represents a built-in shell command.
 * @name: The name of the built-in command.
 * @function: A pointer to the function that implements the comand
 */

struct builtin {
  char *name;
  void (*function)(char **args, int argc, char *command);
};

typedef struct builtin BuiltInCommand;

int execute_builtin(char **args, char *command);
void exit_builtin(char **args, int argc, char *command);
void env_builtin(char **args, int argc, char *command);
void clear_builtin(char **args, int argc, char *command);
void cd_builtin(char **args, int argc, char *command);
void setenv_builtin(char **args, int argc, char *command);
void _unsetenv(char **args, int argc, char *command);
int count_elements(char **array);
void call_signal(void);
char *get_input(void);

#endif
