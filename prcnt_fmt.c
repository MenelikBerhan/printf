#include "main.h"

/**
 * prcnt_fmt - creates a string "%" for %% conversion specification.
 * @data: A void pointer. Not Used.
 * @fmt: An FMT type format specifier.
 *
 * Return: The string "%" if fmt->type = "%" or empty string otherwise.
*/

char *prcnt_fmt(void *data __attribute__((unused)), FMT *fmt)
{
	char *str;

	if (fmt->type[0] == '%')
	{
		str = malloc(sizeof(char) * 2);
		str[1] = '\0';
		str[0] = '%';
	}
	else
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}

	return (str);
}
