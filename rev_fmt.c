#include "main.h"

/**
 * rev_fmt - reverses the string data.
 * @args: variadic argument list
 * @fmt: format specifier.
 *
 * Return: the reversed string.
 */

char *rev_fmt(va_list args, FMT *fmt)
{
	char *s, *str;
	int i, len = 0;
	(void)fmt;

	s = va_arg(args, char *);

	if (s)
	{
		for (i = 0; s[i]; i++)
			len++;
	}
	else
		len = 2;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	str[len] = '\0';
	if (!s)
	{
		/* puts("in if (!s)"); */
		str[0] = '%';
		str[1] = 'r';
		return (str);
	}

	for (i = 0; i < len; i++)
		str[i] = s[len - 1 - i];

	return (str);
}
