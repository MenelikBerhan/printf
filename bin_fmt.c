#include "main.h"
#include <stdint.h>

/**
 * bin_fmt - converts an integer into binary.
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *bin_fmt(va_list args, FMT *fmt)
{
	unsigned long n = va_arg(args, unsigned int);
	int i = 1;
	char *num = malloc(i + 1);

	if (!num)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	base_convert(n, 2, 0, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	return (num);
}
