#include "main.h"

/**
 * base_convert - converts an integer into the based version as a string
 * @n: integer to be converted
 * @base: base to convert to
 * @hex_cap: if base is 16, use chars in caps or not
 * @neg: is @n negative or not
 * @i: no of recursive calls
 * @res: buffer to store the string
 */
void base_convert(long n, int base, int hex_cap, int neg, int *i, char **res)
{
	long num = n;
	int j = (*i)++, k;
	char *hex = "0123456789abcdef";
	char *hex_caps = "0123456789ABCDEF";

	*res = _realloc(*res, (j + 1));
	num /= base;
	if (num != 0)
		base_convert(num, base, hex_cap, neg, i, res);
	k = (*i) - (neg ? j : j + 1);
	if (!hex_cap)
		(*res)[k] = hex[n % base];
	else
		(*res)[k] = hex_caps[n % base];
}
