#include "main.h"

/**
 * pointer_fmt - converts a pointer address to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
String pointer_fmt(va_list *args, FMT *fmt)
{
	String num;
	long ptr = va_arg(*args, long);
	int i = 1, factor;
	char nil[] = "(nil)";

	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	base_convert(ptr, 16, 0, 0, &i, &num.s);
	num.s[i] = '\0';
	i += 2;
	num.s = realloc(num.s, i + 1);
	memmove(&num.s[2], &num.s[0], i + 1);
	num.s[0] = '0';
	num.s[1] = 'x';
	if (!ptr)
	{
		num.s = realloc(num.s, 6);
		strcpy(num.s, nil);
		i = 6;
	}
	if (i < fmt->width)
	{
		num.s = realloc(num.s, (sizeof(char) * (fmt->width + 1)));
		if (!fmt->left)
		{
			factor = fmt->width - i + 1;
			memmove(&num.s[factor], &num.s[0], i);
			memset(num.s, fmt->leading, factor);
		}
		else
			for (; i <= fmt->width; i++)
				num.s[i - 1] = ' ';
		num.s[fmt->width] = '\0';
	}
	num.len = strlen(num.s);
	return (num);
}
