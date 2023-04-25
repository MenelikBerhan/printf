#include "main.h"

/**
 * sign_int_fmt - converts an integer to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *sign_int_fmt(va_list args, FMT *fmt)
{
	unsigned long n = va_arg(args, long);
	int i = 1;
	char *num = malloc(i + 1);

	if (!num)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (!n)
		n = 0;
	base_convert(n, 10, 0, 0, &i, &num);
	num[i - 1] = '\0';
	i = p_w_int(i, 0, fmt, &num);
	if ((fmt->p_plus || fmt->i_plus))
	{
		i = (i >= fmt->width) ? i : fmt->width;
		num = _realloc(num, i + 1);
		if (i > fmt->width || fmt->left)
			_memmove(&num[1], &num[0], fmt->left ? --i : i);
		num[0] = (fmt->i_plus) ? ' ' : '+';
	}
	return (num);
}
