#include "main.h"
#include <stdint.h>

/**
 * oct_fmt - converts an integer into octal.
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *oct_fmt(va_list args, FMT *fmt)
{
	long n = va_arg(args, long);
	int i = 1;
	char *num = malloc(i + 1);

	base_convert(n, 8, 0, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	return (num);
}
