#include "main.h"

/**
 * printable_str - prints a string
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *printable_str(void *data, FMT *fmt)
{
	char *s = *(char **)data;
	int len = strlen(s);
	char *str = malloc(len * 4 + 1);
	int i, j = 0;
	(void)fmt;

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
