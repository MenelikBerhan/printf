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
	char *ex_char = "SRX%";

	while ((str[i] < 'a' || str[i] > 'z') && !_strchr(ex_char, str[i]))
	{
		if (str[i] == '+')
			spe->p_plus = 1;
		else if (str[i] == ' ')
			spe->i_plus = 1;
		else if (str[i] == '-')
			spe->left = 1;
		else if (str[i] == '.')
			spe->dp = 0;
		else if (str[i] == '0')
		{
			if (spe->dp != -1)
				spe->dp *= 10;
			else if (spe->width == 0 && !spe->left)
				spe->leading = '0';
			else
				spe->width *= 10;
		}
		else if (str[i] == '#')
			spe->base_prefix = 1;
		else if (str[i] > '0' && str[i] <= '9')
		{
			if (spe->dp == -1)
				spe->width = spe->width * 10 + (str[i] - '0');
			else
				spe->dp = spe->dp * 10 + (str[i] - '0');
		}
		i++;
	}
	return (i);
}

/**
 * assign_printer - assigns a printer function to the fmt struct
 * @spe: format struct
 */
void assign_printer(FMT *spe)
{
	char t = spe->type;

	if (t == 'd' || t == 'i')
		spe->printer = int_fmt;
	else if (t == 'u')
		spe->printer = sign_int_fmt;
	else if (t == '%')
		spe->printer = prcnt_fmt;
	else if (t == 'c')
		spe->printer = char_fmt;
	else if (t == 's')
		spe->printer = str_fmt;
	else if (t == 'x' || t == 'X')
		spe->printer = hex_fmt;
	else if (t == 'o')
		spe->printer = oct_fmt;
	else if (t == 'b')
		spe->printer = bin_fmt;
	else if (t == 'p')
		spe->printer = pointer_fmt;
	else if (t == 'S')
		spe->printer = printable_str;
	else if (t == 'r')
		spe->printer = rev_fmt;
	else if (t == 'R')
		spe->printer = rot13_fmt;
}

/**
 * get_specifiers - gets and organises the format specifiers in an input string
 * @str: input string
 *
 * Return: an array of format specifiers, NULL if no format specifiers found.
 */
FMT *get_specifiers(const char *str)
{
	int i = 0, j = 0;
	FMT *specifiers = malloc(sizeof(FMT) * (j + 1)), *spe;

	while (str[i])
	{
		if (str[i] == '%')
		{
			specifiers = _realloc(specifiers, (sizeof(FMT) * (j + 1)));
			spe = &specifiers[j];
			i++;
			spe->width = 0;
			spe->left = 0;
			spe->dp = -1;
			spe->i_plus = 0;
			spe->p_plus = 0;
			spe->leading = ' ';
			spe->base_prefix = 0;

			i = fill_fmt(str, spe, i);

			spe->ex_type = (str[i] == 'l' || str[i] == 'h') ? str[i] : '\0';
			spe->type = (str[i] == 'l' || str[i] == 'h') ? str[i + 1] : str[i];
			i += (str[i] == 'l' || str[i] == 'h') ? 2 : 1;
			assign_printer(spe);
			spe->endidx = i;
			j++;
		}
		else
			i++;
	}
	return (!j ? NULL : specifiers);
}
