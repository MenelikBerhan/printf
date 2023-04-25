#include "main.h"
/**
 * _memset - Fills memory with a constant byte.
 * @s: Memory area to be filled
 * @b: Byte to fill memory area
 * @n: number of bytes to fill in @s
 *
 * Return: Pointer to @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
		s[i++] = b;
	return (s);
}
