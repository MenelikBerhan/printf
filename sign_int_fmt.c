#include "main.h"

/**
 * sign_int_fmt - converts an integer to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String sign_int_fmt(va_list *args, FMT *fmt)
{
	String num;
	unsigned long n = va_arg(*args, unsigned int);
	int i = 1;

	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (!n)
		n = 0;
	base_convert(n, 10, 0, 0, &i, &num.s);
	num.s[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num.s);
	if ((fmt->p_plus || fmt->i_plus))
	{
		i = (i >= fmt->width) ? i : fmt->width;
		num.s = realloc(num.s, i + 1);
		if (i > fmt->width || fmt->left)
			memmove(&num.s[1], &num.s[0], fmt->left ? --i : i);
		num.s[0] = (fmt->i_plus) ? ' ' : '+';
	}
	num.len = strlen(num.s);
	return (num);
}
