#include "utilities.h"
/**
 * _strcpy - Copies a string pointed to
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src) {
  int c = 0;

  while (c >= 0) {
    *(dest + c) = *(src + c);
    if (*(src + c) == '\0')
      break;
    c++;
  }
  return (dest);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater
 * than zero if @s1 is found,
 * respectively, to be less than, to match, or
 * be greater than @s2.
 */

int _strcmp(char *s1, char *s2) {
  int v;

  v = 0;
  while (s1[v] != '\0' && s2[v] != '\0') {
    if (s1[v] != s2[v]) {
      return (s1[v] - s2[v]);
    }
    v++;
  }
  return (0);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src) {
  int c1 = 0, c2 = 0;

  while (*(dest + c1) != '\0') {
    c1++;
  }
  while (c2 >= 0) {
    *(dest + c1) = *(src + c2);
    if (*(src + c2) == '\0')
      break;
    c1++;
    c2++;
  }
  return (dest);
}

/**
 * count_elements - Count the number of elements
 * in a null-terminated array.
 * @array: The input array to count elements from.
 *
 * Return: The number of elements in the array.
 */

int count_elements(char **array) {
  int count = 0;

  while (array[count] != NULL) {
    count++;
  }

  return (count);
}

/**
 * remove_comments - checks fro the first occurence of # in command
 * @command: user input to check
 */

void remove_comments(char *command) {
  int i;

  for (i = 0; command[i] != '\0'; i++) {
    if (command[i] == '#' && (!i || command[i - 1] == ' ')) {
      command[i] = '\0';
      break;
    }
  }
}
