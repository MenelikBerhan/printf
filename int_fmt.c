#include "main.h"

/**
 * inttostr - recursively converts an integer to a string
 * @n: integer to be converted
 * @i: no of recursive calls
 * @res: buffer to store the generated string
 * @neg: is @n a negative number
 */
void inttostr(long n, int *i, char **res, int neg)
{
	long num = n;
	int j = (*i)++, k;
	*res = realloc(*res, (j + 1));
	num /= 10;
	if (num != 0)
		inttostr(num, i, res, neg);
	k = (*i) - (neg ? j : j + 1);
	(*res)[k] = (n % 10 + '0');
}

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
	int neg = n < 0, i = 1, factor;
	char *num = malloc(i + 1);

	if (neg)
	{
		n *= -1;
		num[0] = '-';
		i++;
	}
	inttostr(n, &i, &num, neg);
	num[i] = '\0';
	if (i < fmt->width)
	{
		num = realloc(num, (sizeof(char) * (fmt->width + 1)));
		if (!fmt->left)
		{
			factor = fmt->width - i + 1;
			memmove(&num[neg ? factor + 1 : factor], &num[neg ? 1 : 0], i);
			memset(neg ? &num[1] : num, fmt->leading, factor);
		}
		else
			for (; i <= fmt->width; i++)
				num[i - 1] = ' ';
		num[fmt->width] = '\0';
	}
	if ((fmt->p_plus || fmt->i_plus) && !neg)
	{
		i = (i >= fmt->width) ? i + 1 : fmt->width;
		num = realloc(num, i + 1);
		(i > fmt->width) && memmove(&num[1], &num[0], i);
		num[0] = (fmt->i_plus) ? ' ' : '+';
	}
	return (num);
}
