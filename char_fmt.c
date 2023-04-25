#include "main.h"

/**
 * char_fmt - formats a character based on format specifier fmt.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
 */

char *char_fmt(va_list args, FMT *fmt)
{
	char ch = va_arg(args, int), *str;
	int len, i;

	if (ch < 0)
	{
		str = malloc(3);
		strcpy(str, "%c");
		str[2] = '\0';
		return (str);
	}
	len = fmt->width ? fmt->width : 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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
		str[len - 1] = ch;
		for (i = 0; i < len - 1; i++)
			str[i] = ' ';
	}

	return (str);
}
