#include "main.h"

/**
 * rev_fmt - reverses the string data.
 * @args: variadic argument list
 * @fmt: format specifier.
 *
 * Return: the reversed string.
 */

String rev_fmt(va_list *args, FMT *fmt)
{
	String str;
	char *s = va_arg(*args, char *);
	int i, len = 0;
	(void)fmt;

	if (!s)
	{
		len = 2;
		str.s = malloc(sizeof(char) * (len + 1));
		strcpy(str.s, "%r");
		str.s[2] = '\0';
		str.len = len;
		return (str);
	}
	for (i = 0; s[i]; i++)
		len++;
	str.len = len;
	str.s = malloc(sizeof(char) * (len + 1));
	str.s[len] = '\0';
	for (i = 0; i < len; i++)
		str.s[i] = s[len - 1 - i];
	return (str);
}
