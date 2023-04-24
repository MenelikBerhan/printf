#include "main.h"
#include <stdint.h>

/**
 * bin_fmt - converts an integer into binary.
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *bin_fmt(void *data, FMT *fmt)
{
	long n = *(long *)data;
	int i = 1;
	char *num = malloc(i + 1);

	base_convert(n, 2, 0, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	return (num);
}
