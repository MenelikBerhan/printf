#include "main.h"
#include <stdint.h>

/**
 * bin_fmt - converts an integer into binary.
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String bin_fmt(va_list *args, FMT *fmt)
{
	String num;
	unsigned long n;
	int i = 1;

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);

	n = va_arg(*args, unsigned int);
	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	base_convert(n, 2, 0, 0, &i, &num.s);
	num.s[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num.s);
	num.len = strlen(num.s);
	return (num);
}
