#include "main.h"

/**
 * prcnt_fmt - creates a string "%" for %% conversion specification.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The string "%" if fmt->type = "%" or empty string otherwise.
 */
String prcnt_fmt(va_list *args, FMT *fmt)
{
	String str;
	(void)args;
	(void)fmt;

	str.s = malloc(sizeof(char) * 2);
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str.s[0] = '%';
	str.s[1] = '\0';
	str.len = 1;
	return (str);
}
