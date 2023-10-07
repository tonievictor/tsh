#ifndef UTILITIES_H
#define UTILITIES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include "main.h"

int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _atoi(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void cleanup(char **newEnviron, int numEnvVars);
void freecommands(char *command, char **tokens, char *directory);
char *_strdup(char *src);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, size_t n);
int _puterror(char *err);
void _puts(char *str);
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);

#endif

