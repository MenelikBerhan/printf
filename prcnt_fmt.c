#include "main.h"

/**
 * prcnt_fmt - creates a string "%" for %% conversion specification.
 * @data: A void pointer. Not Used.
 * @fmt: An FMT type format specifier.
 *
 * Return: The string "%" if fmt->type = "%" or empty string otherwise.
 */

char *prcnt_fmt(void *data, FMT *fmt)
{
	char *str = malloc(sizeof(char) * 2);
	(void)data;
	(void)fmt;

	str[0] = '%';
	str[1] = '\0';
	return (str);
}
