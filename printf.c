#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format of which to print
 *
 * Return: no of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	FMT *specifiers = get_specifiers(format), *spe;
	FMT_FUNC printer;
	int i, j = 0, k = 0, size = BUFFER_SIZE;
	char *buffer = malloc(size), *str;

	va_start(args, format);
	puts("starting");
	for (i = 0; format[i]; i++)
	{
		if (k >= size - 1)
		{
			size *= 2;
			buffer = realloc(buffer, size);
		}
		if (format[i] == '%')
		{
			spe = &specifiers[j++];
			printer = spe->printer;
			str = printer(args, spe);
			strcpy(buffer + k, str);
			k += strlen(str);
			i = spe->endidx - 1;
			free(str);
		}
		else
			buffer[k++] = format[i];
	}
	va_end(args);
	return (print_buffer(buffer));
}
