#include "main.h"

/**
 * str_fmt - formats string 'data' based on format specifier fmt.
 * @data: The string to be formatted.
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
*/

char *str_fmt(void *data, FMT *fmt)
{
	char *s = (char *) data, *str;
	int l_str, i, j, l_data;

	/* if (!s)
		s = "(null)"; */
	l_data = strlen(s);
	if (fmt->width >= l_data)
	{
		l_str = fmt->width;
	}
	else
	{
		if (fmt->dp == -1 || fmt->dp >= l_data) 
			l_str = l_data;
		else
			l_str = fmt->dp >= fmt->width ? fmt->dp : fmt->width;
	}
	str = malloc(sizeof(char) * (l_str + 1));
	str[l_str] = '\0';

	if (fmt->left)
	{
		if (fmt->dp != -1 && fmt->dp < l_data)
		{
			for (i = 0; i < fmt->dp; i++)
				str[i] = s[i];
			for (; i < l_str; i++)
				str[i] = ' ';
		}
		else if (fmt->dp >= l_data)
		{
			for (i = 0; i < l_data; i++)
				str[i] = s[i];
			for (; i < l_str; i++)
				str[i] = ' ';
		}
	}
	else
	{
		if (fmt->dp != -1 && fmt->dp < l_data)
		{
			for (i = 0; i < l_str - fmt->dp; i++)
				str[i] = ' ';
			for (j = 0; i < l_str, j < fmt->dp; i++, j++)
				str[i] = s[j];
			
		}
		else if (fmt->dp >= l_data)
		{
			for (i = 0; i < l_str - l_data; i++)
				str[i] = ' ';
			for (j = 0; i < l_str, j < l_data; i++, j++)
				str[i] = s[j];
		}
	}

	return (str);
}