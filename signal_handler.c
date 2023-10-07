#include "utilities.h"
#include "main.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigint(int sig)
{
	(void)sig;
	_putchar('\n');
	print_dollar();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigquit(int sig)
{
	(void)sig;
	_putchar('\n');
	print_dollar();
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
	(void)sig;
	_puts("\n");
	print_dollar();
}

