#include "main.h"

/**
 * int_fmt - converts an integer to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *int_fmt(va_list args, FMT *fmt)
{
	long n = va_arg(args, long);
	int neg = n < 0, i = 1, width, dp;
	char *num = malloc(i + 1);

	if (neg)
	{
		n *= -1;
		num[0] = '-';
		i++;
	}
	base_convert(n, 10, 0, neg, &i, &num);
	num[i - 1] = '\0';
	dp = (i - 1) < fmt->dp;
	width = (i - 1 < fmt->width);
	i = p_w_int(i, neg, fmt, &num);
	if ((fmt->p_plus || fmt->i_plus) && !neg)
	{
		i = (i >= fmt->width) ? i : fmt->width;
		num = realloc(num, i + 1);
		if (i > fmt->width || fmt->left)
			memmove(&num[1], &num[0], fmt->left ? --i : i);
		num[0] = (fmt->i_plus || dp || width) ? ' ' : '+';
	}
	return (num);
}
