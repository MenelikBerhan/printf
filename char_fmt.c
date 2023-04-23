#include "main.h"

/**
 * char_fmt - formats a character based on format specifier fmt.
 * @c: A pointer to the character.
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
*/

char *char_fmt(void *data, FMT *fmt)
{
	char ch = *(char *) data, *str;
	int len, i;

	len = fmt->width ? fmt->width : 1;

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (!fmt->width)
	{
		str[0] = ch;
		return (str);
	}

	if (fmt->left)
	{
		str[0] = ch;
		for (i = 1; i < len; i++)
			str[i] = ' ';
	}
	else
	{
		str[len -1] = ch;
		for (i = 0; i < len - 1; i++)
			str[i] = ' ';
	}

	return (str);
}