#include "main.h"
#include "utilities.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point of my program
 *
 * Return: 0 if successful or an Exit error
 */
int main(void)
{
	char *command, **tokens_array;
	int is_terminal = isatty(STDIN_FILENO), flag = 1, status_code = 0, space;

	call_signal();
	while (1)
	{
		flag = is_terminal;
		if (is_terminal)
			print_dollar();
		command = read_command();
		if (!command)
		{
			free(command);
			if (errno != 0)
				status_code = 2;
			_putchar('\n');
			break;
		}
		space = _stripstr(command);
		if (space == 1)
		{
			free(command);
			continue;
		}
		remove_comments(command);
		tokens_array = seperate_input(command);
		if (command[0] == '\0' || _strcmp(command, "\n") == 0)
			continue;
		if (execute_builtin(tokens_array, command) == 0)
		{
			free(command);
			free(tokens_array);
			errno = 0;
			continue;
		}
		status_code = execute_command(command, tokens_array);
		if (status_code == 0)
			errno = status_code;
	}
	return (status_code);
}

/**
 * execute_command - function to excute commands
 * @command: user input
 * @tokens_array: tokenized array of inputs
 *
 * Return: status
 */

int execute_command(char *command, char **tokens_array)
{
	int status;

	if (tokens_array[0][0] == '/' || tokens_array[0][0] == '.')
	{
		status = runpathcmd(command, tokens_array);
	}
	else
	{
		status = runpathlesscmd(command, tokens_array);
	}

	return (status);
}

/**
 * call_signal - functute to call signal commands
 */

void call_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);
}

