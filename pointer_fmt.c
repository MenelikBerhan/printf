#include "main.h"

/**
 * pointer_fmt - converts a pointer address to a string
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the string
 */
char *pointer_fmt(va_list args, FMT *fmt)
{
	long ptr = va_arg(args, long);
	int i = 1, factor, j;
	char *num = malloc(i + 1), nil[] = "(nil)";

	if (!num)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	base_convert(ptr, 16, 0, 0, &i, &num);
	num[i] = '\0';
	i += 2;
	num = _realloc(num, i + 1);
	_memmove(&num[2], &num[0], i + 1);
	num[0] = '0';
	num[1] = 'x';
	if (!ptr)
	{
		num = _realloc(num, 6);
		for (j = 0; j <= 6; j++)
			num[j] = nil[j];
		i = 6;
	}
	if (i < fmt->width)
	{
		num = _realloc(num, (sizeof(char) * (fmt->width + 1)));
		if (!fmt->left)
		{
			factor = fmt->width - i + 1;
			_memmove(&num[factor], &num[0], i);
			_memset(num, fmt->leading, factor);
		}
		else
			for (; i <= fmt->width; i++)
				num[i - 1] = ' ';
		num[fmt->width] = '\0';
	}
	return (num);
}
