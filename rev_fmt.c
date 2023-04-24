#include "main.h"

/**
 * rev_fmt - reverses the string data.
 * @data: string to be reversed.
 * @fmt: format specifier.
 *
 * Return: the reversed string.
*/

char *rev_fmt(void *data, FMT *fmt)
{
	char *str = (char *) data, temp;
	int i, len = 0;

	for (i = 0; str[i]; i++)
		len++;

	for (i = 0; i < len / 2; i++)
	{
		temp = *(str + len - 1 - i);

		*(str + (len - 1 - i)) = *(str + i);
		*(str + i) = temp;
	}

	return (str);
}