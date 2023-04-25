#include "main.h"

/**
 * printable_str - prints a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *printable_str(va_list args, FMT *fmt)
{
	char *s = va_arg(args, char *);
	int len;
	char *str;
	int i, j = 0;
	(void)fmt;

	if (!s)
		s = "";

	len = _strlen(s);
	str = malloc(len * 4 + 1);
	if (!str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < len; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			str[j++] = '\\';
			str[j++] = 'x';
			str[j++] = "0123456789ABCDEF"[(unsigned char)s[i] >> 4];
			str[j++] = "0123456789ABCDEF"[(unsigned char)s[i] & 0x0F];
		}
		else
		{
			str[j++] = s[i];
		}
	}
	str[j] = '\0';

	return (str);
}
