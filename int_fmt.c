#include "main.h"

/**
 * int_fmt - converts an integer to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String int_fmt(va_list *args, FMT *fmt)
{
	String num;
	long n;
	int neg, i = 1, width, dp;

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);

	n = va_arg(*args, int);
	neg = n < 0;
	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc2");
		exit(EXIT_FAILURE);
	}
	if (!n)
		n = 0;
	if (neg)
	{
		n *= -1;
		num.s[0] = '-';
		i++;
	}
	base_convert(n, 10, 0, neg, &i, &num.s);
	num.s[i - 1] = '\0';
	dp = (i - 1) < fmt->dp;
	width = (i - 1) < fmt->width;
	i = p_w_int(i, neg, fmt, &num.s);
	if ((fmt->p_plus || fmt->i_plus) && !neg)
	{
		i = (i >= fmt->width) ? i : fmt->width;
		num.s = realloc(num.s, i + 1);
		if (i > fmt->width || fmt->left)
			memmove(&num.s[1], &num.s[0], fmt->left ? --i : i);
		num.s[0] = (fmt->i_plus || dp || width) ? ' ' : '+';
	}
	num.len = strlen(num.s);
	return (num);
}
