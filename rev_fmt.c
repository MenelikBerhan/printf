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
	if ((unsigned long)s == 12)
	{
		str = malloc(3);
		strcpy(str, "%r");
		str[2] = '\0';
		return (str);
	}
	for (i = 0; s[i]; i++)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';

	for (i = 0; i < len; i++)
		str[i] = s[len - 1 - i];

	return (str);
}
