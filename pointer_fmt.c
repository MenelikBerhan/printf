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
	long ptr;
	int i = 1;
	char nil[] = "(nil)";

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);
	ptr = va_arg(*args, long);
	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (ptr == -1)
	{
		i = 16;
		num.s = realloc(num.s, i + 1);
		strcpy(num.s, "ffffffffffffffff");
	}
	else
		base_convert(ptr, 16, 0, 0, &i, &num.s);
	
	ptr_fmt(&num, i);

	if (!ptr)
	{
		num.s = realloc(num.s, 6);
		strcpy(num.s, nil);
		i = 6;
	}
	if (i < fmt->width)
		pointer_width(&num.s, fmt, i);
	num.len = strlen(num.s);
	return (num);
}

/**
 * pointer_width - handles width flag for pointer specifiers
 * @s: buffer holding integer string
 * @fmt: format specifier struct
 * @i: current index
 */
void pointer_width(char **s, FMT *fmt, int i)
{
	int factor;

	*s = realloc(*s, (sizeof(char) * (fmt->width + 1)));
	if (!fmt->left)
	{
		factor = fmt->width - i + 1;
		memmove(*s + factor, *s, i);
		memset(*s, fmt->leading, factor);
	}
	else
		for (; i <= fmt->width; i++)
			(*s)[i - 1] = ' ';
	(*s)[fmt->width] = '\0';
}

/**
 * ptr_fmt - sets element values for a String pointed by num.
 * @num: A pointer to a String.
 * @i: length of s element of num, which is a string.
 *
 */
void ptr_fmt(String *num, int i)
{
	num->s[i] = '\0';
	i += 2;
	num->s = realloc(num->s, i + 1);
	memmove(&num->s[2], &num->s[0], i + 1);
	num->s[0] = '0';
	num->s[1] = 'x';
}
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
	long ptr;
	int i = 1;
	char nil[] = "(nil)";

	if (fmt->width == -2)
		fmt->width = va_arg(*args, int);
	if (fmt->dp == -2)
		fmt->dp = va_arg(*args, int);
	ptr = va_arg(*args, long);
	num.s = malloc(i + 1);
	if (!num.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (ptr == -1)
	{
		i = 16;
		num.s = realloc(num.s, i + 1);
		strcpy(num.s, "ffffffffffffffff");
	}
	else
		base_convert(ptr, 16, 0, 0, &i, &num.s);
	
	ptr_fmt(&num, i);

	if (!ptr)
	{
		num.s = realloc(num.s, 6);
		strcpy(num.s, nil);
		i = 6;
	}
	if (i < fmt->width)
		pointer_width(&num.s, fmt, i);
	num.len = strlen(num.s);
	return (num);
}
