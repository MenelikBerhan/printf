#include "main.h"

/**
 * rot13_fmt - formats string data using rot13 cipher.
 * @args: variadic argument list
 * @fmt: format specifier.
 *
 * Return: the rot13'ed string.
 */

String rot13_fmt(va_list *args, FMT *fmt)
{
	String str;
	char *c_i = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *c_o = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(*args, char *);
	int i, j, len = 0;
	(void)fmt;

	if (s)
		for (i = 0; s[i]; i++)
			len++;
	else
		len = 2;
	str.s = malloc(sizeof(char) * (len + 1));
	str.len = len;
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str.s[len] = '\0';
	if (!s)
	{
		str.s[0] = '%';
		str.s[1] = 'R';
		return (str);
	}
	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == c_i[j])
			{
				str.s[i] = c_o[j];
				break;
			}
		}
		if (j == 52)
			str.s[i] = s[i];
	}
	return (str);
}
