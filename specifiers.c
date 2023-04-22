#include "main.h"

/**
 * fill_fmt - fill appropriate fields in a FMT struct
 * @str: input string
 * @spe: format details
 * @i: start index
 *
 * Return: stop index
 */
int fill_fmt(const char *str, FMT *spe, int i)
{
	while (str[i] < 'a' || str[i] > 'z')
	{
		switch (str[i])
		{
		case '+':
			spe->p_plus = true;
			break;
		case ' ':
			spe->i_plus = true;
			break;
		case '-':
			spe->left = true;
			break;
		case '.':
			spe->dp = 0;
			break;
		case '0':
			if (spe->width == 0 && !spe->left)
				spe->leading = '0';
			else
				spe->width *= 10;
			break;
		case '#':
			spe->base_prefix = true;
			break;
		default:
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (spe->dp == -1)
					spe->width = spe->width * 10 + (str[i] - '0');
				else
					spe->dp = spe->dp * 10 + (str[i] - '0');
			}
			break;
		}
		i++;
	}
	return (i);
}

/**
 * get_specifiers - gets and organises the format specifiers in an input string
 * @str: input string
 * @count: buffer to store no of specifiers
 *
 * Return: an array of format specifiers, NULL if no format specifiers found.
 */
FMT *get_specifiers(const char *str, int *count)
{
	int i = 0, j = 0, k = 0;
	FMT *specifiers = malloc(sizeof(FMT) * (j + 1)), *spe;

	while (str[i])
	{
		if (str[i] == '%')
		{
			specifiers = realloc(specifiers, (sizeof(FMT) * (j + 1)));
			spe = &specifiers[j];
			i++;
			spe->width = 0;
			spe->left = false;
			spe->dp = -1;
			spe->i_plus = false;
			spe->p_plus = false;
			spe->leading = ' ';
			spe->base_prefix = false;

			i = fill_fmt(str, spe, i);

			k = (str[i] == 'l' || str[i] == 'h') ? 2 : 1;
			strncpy(spe->type, &str[i], k);
			spe->type[k] = '\0';
			i += k;
			j++;
		}
		else
			i++;
	}
	*count = j;
	return (!j ? NULL : specifiers);
}
