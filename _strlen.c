#include "main.h"
/**
 * _strlen - computes the length of a string
 * @s: string whose length is to be computed
 *
 * Return: length of string @s
 */
int _strlen(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen(++s));
}
