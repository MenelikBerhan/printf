#include "main.h"

/**
 * rot13_fmt - formats string data using rot13 cipher.
 * @args: variadic argument list
 * @fmt: format specifier.
 *
 * Return: the rot13'ed string.
 */

char *rot13_fmt(va_list args, FMT *fmt)
{
	char *c_i = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *c_o = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(args, char *), *str;
	int i, j, len = 0;
	(void)fmt;

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
		str[0] = '%';
		str[1] = 'R';
		return (str);
	}
	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == c_i[j])
			{
				str[i] = c_o[j];
				break;
			}
		}
		if (j == 52)
			str[i] = s[i];
	}
	return (str);
}
