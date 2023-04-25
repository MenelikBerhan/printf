#include "main.h"

/**
 * _memcpy - moves data from 1 memory location to another
 * @dest: destination location
 * @src: source location
 * @n: no of bytes of data to move
 *
 * Return: pointer to destination
 */
char *_memcpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
