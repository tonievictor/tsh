#include "utilities.h"

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */

int _atoi(const char *str) {
  int i;
  unsigned int num;

  i = 0;
  num = 0;

  while (str[i] != '\0') {
    if (str[i] == '-')
      return (1);
    else if (str[i] >= '0' && str[i] <= '9')
      num = (num * 10) + (str[i] - '0');
    else
      return (1);
    i++;
  }
  return (num);
}

/**
 * _strncmp - Compare two strings up to a
 * specified number of characters.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n
 * characters, an integer less
 * than, or greater than zero if str1 is found,
 * respectively, to be less
 * than, to match, or be greater than str2.
 */

int _strncmp(const char *str1, const char *str2, size_t n) {

  while (n > 0 && *str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
    n--;
  }

  if (n == 0) {
    return (0);
  } else {
    return (1);
  }
}

/**
 * _strlen - Function to return the length of a string
 * @s: String pointer to the string whose length is to be returned
 * Return: Length of string
 */
int _strlen(const char *s) {
  int lenstr = 0;

  while (*s != '\0') {
    lenstr++;
    s++;
  }
  return (lenstr);
}

/**
 * _strdup - Duplicate a string.
 * @src: The source string to duplicate.
 *
 * Description:
 * This function duplicates a given null-terminated
 * string @src and returns a
 * pointer to a newly allocated string that contains a copy of @src.
 *
 * Return: A pointer to the duplicated string if successful,
 * or NULL on failure.
 *
 * Note: The caller is responsible for freeing the
 * memory allocated for the
 * duplicated string when it is no longer needed.
 */

char *_strdup(char *src) {
  char *dest;
  size_t len;

  if (src == NULL) {
    return (NULL);
  }

  len = strlen(src);

  dest = (char *)malloc((len + 1) * sizeof(char));

  if (dest == NULL) {
    return (NULL);
  }

  _strcpy(dest, src);

  return (dest);
}

/**
 * _stripstr - function to check if a user input is only just
 * whitespaces
 * @command: user input
 *
 * Return: 0 if a non-white space is encountered else 1
 */

int _stripstr(char *command) {
  while (*command) {
    if (*command != ' ') {
      return (0);
    }
    command++;
  }
  return (1);
}
