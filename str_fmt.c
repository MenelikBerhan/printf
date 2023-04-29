#include "main.h"

/**
 * str_buffer_size - finds the appropraite size for a buffer on which
 * a formatted string is to be written.
 * @width: width specifier.
 * @dp: precision specifier.
 * @l_data: length of string to be formatted.
 *
 * Return: The required buffer length excluding terminating null.
 */
int str_buffer_size(int width, int dp, int l_data)
{
	int l_str;

	if (width >= l_data)
	{
		l_str = width;
	}
	else
	{
		if (dp == -1 || dp >= l_data)
			l_str = l_data;
		else
			l_str = dp >= width ? dp : width;
	}

	return (l_str);
}

/**
 * str_buffer_write - Writes on str a formatted src string based on fmt.
 * @src: The string to be formatted.
 * @l_src: Length of src string.
 * @str: The buffer to write to.
 * @l_str: Length of str.
 * @fmt: An FMT type format specifier.
 */
void str_buffer_write(char *src, int l_src, char *str, int l_str, FMT *fmt)
{
	int i, j, len;

	len = (fmt->dp != -1 && fmt->dp < l_src) ? fmt->dp : l_src;

	if (fmt->left)
	{
		for (i = 0; i < len; i++)
			str[i] = src[i];
		for (; i < l_str; i++)
			str[i] = ' ';
	}
	else
	{
		for (i = 0; i < l_str - len; i++)
			str[i] = ' ';
		for (j = 0; i < l_str && j < len; i++, j++)
			str[i] = src[j];
	}
}

/**
 * str_fmt - formats string 'data' based on format specifier fmt.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
 */
String str_fmt(va_list *args, FMT *fmt)
{
	String str;
	char *s;
	int l_str, l_data;

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);

	s = va_arg(*args, char *);
	if ((unsigned long)s == 2147484671)
	{
		l_str = 2;
		str.s = malloc(l_str + 1);
		strcpy(str.s, "%s");
		str.s[l_str] = '\0';
		str.len = l_str;
		return (str);
	}
	if (!s)
		s = "(null)";
	l_data = strlen(s);
	l_str = str_buffer_size(fmt->width, fmt->dp, l_data);
	str.s = malloc(sizeof(char) * (l_str + 1));
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str.s[l_str] = '\0';
	str.len = l_str;
	str_buffer_write(s, l_data, str.s, l_str, fmt);
	return (str);
}
