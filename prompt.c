#include "main.h"
#include "utilities.h"
#include <unistd.h>

/**
 * print_dollar - Print the dollar sign character ('$').
 */

void print_dollar(void) {
  _putchar('$');
  _putchar(' ');
  fflush(stdout);
}

/**
 * _putchar - writes the character  c to the stdout
 * @c: This is the character that will be printed
 * Return: 1 (indicates success)
 * If an error occurs, -1 is returned and the appropraite error is set
 */

int _putchar(char c) { return (write(1, &c, 1)); }
