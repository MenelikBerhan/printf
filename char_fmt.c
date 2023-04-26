#include "main.h"

/**
 * char_fmt - formats a character based on format specifier fmt.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
 */

String char_fmt(va_list *args, FMT *fmt)
{
	String str;
	char ch = va_arg(*args, unsigned int);
	int len, i;

	if (ch < 0 || !ch)
	{
		len = !ch ? 1 : 2;
		str.s = malloc(len + 1);
		strcpy(str.s, !ch ? "\0" : "%c");
		str.s[len] = '\0';
		str.len = len;
		return (str);
	}
	len = fmt->width ? fmt->width : 1;
	str.len = len;
	str.s = malloc(sizeof(char) * (len + 1));
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str.s[len] = '\0';
	if (!fmt->width)
	{
		str.s[0] = ch;
		return (str);
	}
	if (fmt->left)
	{
		str.s[0] = ch;
		for (i = 1; i < len; i++)
			str.s[i] = ' ';
	}
	else
	{
		str.s[len - 1] = ch;
		for (i = 0; i < len - 1; i++)
			str.s[i] = ' ';
	}
	return (str);
}
