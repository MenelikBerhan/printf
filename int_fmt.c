#include "main.h"

/**
 * int_fmt - converts an integer to a string
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *int_fmt(void *data, FMT *fmt)
{
	long n = *(long *)data;
	int neg = n < 0, i = 1;
	char *num = malloc(i + 1);

	if (neg)
	{
		n *= -1;
		num[0] = '-';
		i++;
	}
	base_convert(n, 10, 0, neg, &i, &num);
	num[i - 1] = '\0';
	printf("%s\t", num);
	i = p_w_int(i, fmt->dp, fmt->width, fmt->left, neg, fmt->leading, &num);
	printf("%s\n", num);
	if ((fmt->p_plus || fmt->i_plus) && !neg)
	{
		i = (i >= fmt->width) ? i : fmt->width;
		num = realloc(num, i + 1);
		if (i > fmt->width || fmt->left)
			memmove(&num[1], &num[0], fmt->left ? --i : i);
		num[0] = (fmt->i_plus) ? ' ' : '+';
	}
	return (num);
}
