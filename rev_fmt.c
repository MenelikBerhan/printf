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
	char *s = (char *) data, *str;
	int i, len = 0;
	(void)fmt;

	for (i = 0; s[i]; i++)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';

	for (i = 0; i < len; i++)
		str[i] = s[len - 1 - i];

	return (str);
}
