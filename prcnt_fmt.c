#include "main.h"

/**
 * prcnt_fmt - creates a string "%" for %% conversion specification.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The string "%" if fmt->type = "%" or empty string otherwise.
 */
char *prcnt_fmt(va_list args, FMT *fmt)
{
	char *str = malloc(sizeof(char) * 2);
	(void)args;
	(void)fmt;

	str[0] = '%';
	str[1] = '\0';
	return (str);
}
