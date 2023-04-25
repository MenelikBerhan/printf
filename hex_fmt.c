#include "main.h"
#include <stdint.h>

/**
 * hex_fmt - converts an integer into hexadecimal
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *hex_fmt(va_list args, FMT *fmt)
{
	long n = va_arg(args, long);
	int i = 1, hex_cap = fmt->type == 'X';
	char *num = malloc(i + 1);

	if (!num)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	base_convert(n, 16, hex_cap, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	return (num);
}
