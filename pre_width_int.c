#include "main.h"

/**
 * p_w_int - handles precision and width flags for integers of all bases
 * @i: current length
 * @n: is the num negative
 * @fmt: format struct
 * @num: buffer to store string
 *
 * Return: final precision
 */
int p_w_int(int i, int n, FMT *fmt, char **num)
{
	int factor;

	if (i < fmt->dp)
	{
		*num = realloc(*num, (sizeof(char) * (fmt->dp + 1)));
		factor = fmt->dp - i + 1;
		memmove(*num + (n ? 1 : 0) + factor, *num + (n ? 1 : 0), i);
		memset(*num + (n ? 1 : 0), '0', factor);
		i = fmt->dp;
	}
	if (fmt->base_prefix)
	{
		i += fmt->type == 'o' ? 1 : 2;
		*num = realloc(*num, i + 1);
		memmove(*num + 2, *num, fmt->left ? --i : i);
		(*num)[0] = '0';
		if (fmt->type == 'x' || fmt->type == 'X')
			(*num)[1] = 'x';
	}
	if (i < fmt->width)
	{
		*num = realloc(*num, (sizeof(char) * (fmt->width + 1)));
		factor = fmt->width - i;
		memset(*num + (n ? 1 : 0) + i, fmt->dp > 0 ? ' ' : fmt->leading, factor);
		if (!fmt->left)
		{
			memmove(*num + (n ? 1 : 0) + factor, *num + (n ? 1 : 0), i);
			memset(*num + (n ? 1 : 0), ' ', factor);
		}
	}
	(*num)[fmt->width] = '\0';
	return (i);
}
