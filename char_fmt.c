#include "main.h"

/**
 * char_w_l - formats a character ch based on format specifier fmt.
 * and stores it in a String pointed by str.
 * @str: String pointer.
 * @fmt: An FMT type format specifier.
 * @ch: A cahracter to be formatted.
 * @len: Length of ch.
 *
 */
void char_w_l(String *str, FMT *fmt, char ch, int len)
{
	int i;

	if (!fmt->width)
	{
		str->s[0] = ch;
		return;
	}
	if (fmt->left)
	{
		str->s[0] = ch;
		for (i = 1; i < len; i++)
			str->s[i] = ' ';
	}
	else
	{
		str->s[len - 1] = ch;
		for (i = 0; i < len - 1; i++)
			str->s[i] = ' ';
	}
}

/**
 * char_fmt - formats a character based on format specifier fmt.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The formatted string.
 */
String char_fmt(va_list *args, FMT *fmt)
{
	String str;
	char ch;
	int len;

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);

	ch = va_arg(*args, unsigned int);
	if (ch < 0 || !ch)
	{
		len = !ch ? 1 : 2;
		str.s = malloc(len + 1);
		strcpy(str.s, !ch ? "\0" : "%c");
		str.s[len] = '\0';
		str.len = len;
		return (str);
	}
	len = fmt->width ? fmt->width : 1;
	str.len = len;
	str.s = malloc(sizeof(char) * (len + 1));
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str.s[len] = '\0';
	char_w_l(&str, fmt, ch, len);
	return (str);
}
