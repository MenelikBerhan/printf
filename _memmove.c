#include "main.h"

/**
 * _memmove - moves data from 1 memory location to another
 * @dest: destination location
 * @src: source location
 * @n: no of bytes of data to move
 *
 * Return: pointer to destination
 */
char *_memmove(char *dest, char *src, int n)
{
	char *temp;

	if (dest <= src || dest >= (src + n))
		for (temp = dest; n > 0; n--)
			*temp++ = *src++;
	else
	{
		temp = dest + n - 1;
		src = src + n - 1;
		for (; n > 0; n--)
			*temp-- = *src--;
	}
	return (dest);
}
