#include "main.h"

/**
 * rot13_fmt - formats string data using rot13 cipher.
 * @data: string to be rot13'ed.
 * @fmt: format specifier.
 *
 * Return: the rot13'ed string.
*/

char *rot13_fmt(void *data, FMT *fmt)
{
	char *c_i = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *c_o = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = (char *) data, *str;
	int i, j, len = 0;
	(void)fmt;

	for (i = 0; s[i]; i++)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';

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
