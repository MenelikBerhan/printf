#include "main.h"

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
	int factor, factor2;

	--i;

	if (fmt->dp != -1 || fmt->left)
		fmt->leading = ' ';
	if (strchr("xXob", fmt->type))
	{
		n = 0;
		fmt->i_plus = 0;
		fmt->p_plus = 0;
	}

	if ((fmt->dp == -1 || fmt->dp == 0) && (i == 1 && (*num)[0] == '0'))
		fmt->base_prefix = 0;

	if (!fmt->dp)
	{
		fmt->leading = ' ';
		if (i == 1 && (*num)[0] == '0')
		{
			*num = realloc(*num, 0);
			i = 0;
		}
	}

	if (i < fmt->dp)
	{
		*num = realloc(*num, (sizeof(char) * (fmt->dp + 1)));
		factor = fmt->dp - i;
		memmove(*num + factor, *num, i);
		memset(*num, '0', factor);
		i = fmt->dp;
	}

	factor = 0;
	if (strchr("xXob", fmt->type) && fmt->base_prefix)
		factor = fmt->type == 'o' ? 1 : 2;
	if (strchr("dui", fmt->type))
		factor = (n || fmt->i_plus || fmt->p_plus) ? 1 : 0;

	if (i + factor < fmt->width && !fmt->left && fmt->leading == '0')
	{
		*num = realloc(*num, (sizeof(char) * (fmt->width + 1)));
		factor2 = fmt->width - i;
		memmove(*num + factor2, *num, i);
		memset(*num + factor, '0', (factor2 - factor));
		if (strchr("xXob", fmt->type) && fmt->base_prefix)
		{
			(*num)[0] = '0';
			if (strchr("xXb", fmt->type))
				(*num)[1] = strchr("xXb", fmt->type)[0];
		}
		if (strchr("dui", fmt->type) && (n || fmt->p_plus || fmt->i_plus))
		{
			if (n)
				(*num)[0] = '-';
			else
				(*num)[0] = " +"[fmt->p_plus];
		}
		return (fmt->width);
	}

	if (factor)
	{
		*num = realloc(*num, (sizeof(char) * (i + factor + 1)));
		memmove(*num + factor, *num, i);
		if (strchr("xXob", fmt->type) && fmt->base_prefix)
		{

			(*num)[0] = '0';
			if (strchr("xXb", fmt->type))
				(*num)[1] = strchr("xXb", fmt->type)[0];
		}
		if (strchr("dui", fmt->type) && (n || fmt->p_plus || fmt->i_plus))
		{
			if (n)
				(*num)[0] = '-';
			else
				(*num)[0] = " +"[fmt->p_plus];
		}
		i += factor;
	}

	if (i < fmt->width)
	{
		factor = fmt->width - i;
		*num = realloc(*num, (sizeof(char) * (fmt->width + 1)));
		if (fmt->left)
		{
			memset(*num + i, fmt->leading, factor);
		}
		else
		{
			memmove(*num + factor, *num, i);
			memset(*num, fmt->leading, factor);
		}
		i = fmt->width;
	}

	return (i);
}
