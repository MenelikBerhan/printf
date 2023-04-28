#include "main.h"

/**
 * base_convert - converts an integer into the based version as a string
 * @n: integer to be converted
 * @b: base to convert to
 * @cap: if base is 16, use chars in caps or not
 * @neg: is @n negative or not
 * @i: no of recursive calls
 * @r: buffer to store the string
 */
void base_convert(unsigned long n, int b, int cap, int neg, int *i, char **r)
{
	unsigned long num = n;
	int j = (*i)++, k;
	char *hex = "0123456789abcdef";
	char *hex_caps = "0123456789ABCDEF";

	*r = realloc(*r, (j + 1));
	num /= b;
	if (num != 0)
		base_convert(num, b, cap, neg, i, r);
	k = (*i) - (neg ? j : j + 1);
	if (!cap)
		(*r)[k] = hex[n % b];
	else
		(*r)[k] = hex_caps[n % b];
}
