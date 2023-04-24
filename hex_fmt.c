#include "main.h"
#include <stdint.h>

/**
 * hex_fmt - converts an integer into hexadecimal
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *hex_fmt(void *data, FMT *fmt)
{
	long n = *(long *)data;
	int i = 1, hex_cap = fmt->type == 'X';
	char *num = malloc(i + 1);

	base_convert(n, 16, hex_cap, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	return (num);
}
