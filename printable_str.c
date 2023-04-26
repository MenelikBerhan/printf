#include "main.h"

/**
 * printable_str - prints a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String printable_str(va_list *args, FMT *fmt)
{
	String str;
	char *s = va_arg(*args, char *);
	int len, i, j = 0;
	(void)fmt;

	if (!s)
		s = "";
	len = strlen(s);
	str.s = malloc(len * 4 + 1);
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			str.s[j++] = '\\';
			str.s[j++] = 'x';
			str.s[j++] = "0123456789ABCDEF"[(unsigned char)s[i] >> 4];
			str.s[j++] = "0123456789ABCDEF"[(unsigned char)s[i] & 0x0F];
		}
		else
		{
			str.s[j++] = s[i];
		}
	}
	str.s[j] = '\0';
	str.len = strlen(str.s);
	return (str);
}
