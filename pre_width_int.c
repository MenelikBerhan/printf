#include "main.h"

/**
 * fmt_width - handles the width flags for all interger
 * @i: current length
 * @n: is the num negative
 * @dp: has precision been handled
 * @fmt: format struct
 * @num: buffer to store string
 *
 * Return: final precision
 */
int fmt_width(int i, int n, int dp, FMT *fmt, char **num)
{
	int factor;

	if (i < fmt->width)
	{
		int mn = n && fmt->leading == '0' && !dp;
		*num = realloc(*num, (sizeof(char) * (fmt->width + 1)));
		factor = fmt->width - i;
		memset(*num + i, ' ', factor);
		if (!fmt->left)
		{
			if (fmt->type == 'x' || fmt->type == 'X' || fmt->type == 'b')
			{
				memmove(*num + (mn ? 1 : 0) + 2 + factor, *num + (mn ? 1 : 0) + 2, i);
				memset(*num + (mn ? 1 : 0) + 2, fmt->dp > 0 ? ' ' : fmt->leading, factor);
			}
			else
			{
				memmove(*num + (mn ? 1 : 0) + factor, *num + (mn ? 1 : 0), i);
				memset(*num + (mn ? 1 : 0), fmt->dp > 0 ? ' ' : fmt->leading, factor);
			}
		}
		if (fmt->p_plus)
			(*num)[factor - 1] = '+';
		(*num)[fmt->width] = '\0';
	}
	return (i);
}

/**
 * p_w_int - handles db, base_prefix and width flags for integers
 * @i: current length
 * @n: is the num negative
 * @fmt: format struct
 * @num: buffer to store string
 *
 * Return: final precision
 */
int p_w_int(int i, int n, FMT *fmt, char **num)
{
	int factor, dp;

	--i;
	dp = i < fmt->dp;
	if (i < fmt->dp)
	{
		int mn = n || fmt->p_plus;
		*num = realloc(*num, (sizeof(char) * (fmt->dp + 1 + mn)));
		factor = fmt->dp + mn - i;
		memmove(*num + factor + n, *num + n, i + mn);
		memset(*num, '0', factor + n);
		if (mn)
			(*num)[0] = n ? '-' : '+';
		i = fmt->dp + mn;
	}
	if (fmt->base_prefix && !(fmt->type == 'o' && dp))
	{
		i += fmt->type == 'o' ? 1 : 2;
		*num = realloc(*num, i + 1);
		memmove(*num + (fmt->type == 'o' ? 1 : 2), *num, fmt->left ? --i : i);
		(*num)[0] = '0';
		if (fmt->type == 'x' || fmt->type == 'X' || fmt->type == 'b')
			(*num)[1] = fmt->type;
	}
	return (fmt_width(i, n, dp, fmt, num));
}
