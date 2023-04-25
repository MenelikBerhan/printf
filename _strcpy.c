#include "main.h"
/**
 * _strcpy - Copies a string
 * @dest: Where string is copied to
 * @src: Where string is copied from
 *
 * Return: pointer of the dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
