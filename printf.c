#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format of which to print
 *
 * Return: no of chars printed
 */
int _printf(const char *format, ...)
{
	int i, j = 0, k = 0, size = BUFFER_SIZE;
	FMT *specifiers = get_specifiers(format), *spe;
	FMT_FUNC printer;
	char *str, *spe_str;
	va_list args;

	str = malloc(size);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (k >= size - 1)
		{
			size *= 2;
			str = realloc(str, size);
		}
		if (format[i] == '%')
		{
			spe = &specifiers[j++];
			printer = spe->printer;
			spe_str = printer(va_arg(args, void *), spe);
			strcat(str + k, spe_str);
			k += strlen(spe_str);
			i = spe->endidx;
			free(spe_str);
		}
		else
			str[k++] = format[i];
	}
	va_end(args);
	str[k] = '\0';
	print_buffer(str);
	free(str);
	return (0);
}
