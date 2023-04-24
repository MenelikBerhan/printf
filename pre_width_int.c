#include "main.h"

/**
 * p_w_int - handles precision and width flags for integers of all bases
 * @i: current length
 * @dp: precision
 * @width: width
 * @left: left justify
 * @n: is the num negative
 * @lead: leading character
 * @num: buffer to store string
 *
 * Return: final precision
 */
int p_w_int(int i, int dp, int width, int left, int n, char lead, char **num)
{
	int factor;

	if (i < dp)
	{
		*num = realloc(*num, (sizeof(char) * (dp + 1)));
		factor = dp - i + 1;
		memmove(*num + (n ? 1 : 0) + factor, *num + (n ? 1 : 0), i);
		memset(*num + (n ? 1 : 0), '0', factor);
		i = dp;
	}
	if (i < width)
	{
		*num = realloc(*num, (sizeof(char) * (width + 1)));
		factor = width - i;
		memset(*num + (n ? 1 : 0) + i, dp > 0 ? ' ' : lead, factor);
		if (!left)
		{
			memmove(*num + (n ? 1 : 0) + factor, *num + (n ? 1 : 0), i);
			memset(*num + (n ? 1 : 0), ' ', factor);
		}
	}
	(*num)[width] = '\0';
	return (i);
}
