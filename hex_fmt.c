#include "main.h"
#include <stdint.h>

/**
 * hex_fmt - converts an integer into hexadecimal
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String hex_fmt(va_list *args, FMT *fmt)
{
	String num;
	unsigned long n = sign_int_type(args, fmt);
	int i = 1, hex_cap = fmt->type == 'X';

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);
	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	base_convert(n, 16, hex_cap, 0, &i, &num.s);
	num.s[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num.s);
	num.len = strlen(num.s);
	return (num);
}
