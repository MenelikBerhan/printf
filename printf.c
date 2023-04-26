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
	int i, j = 0, k = 0, size = BUFFER_SIZE;
	FMT *specifiers, *spe;
	FMT_FUNC printer;
	char *buffer, *str;

	if (!format)
		return (-1);
	specifiers = get_specifiers(format);
	buffer = malloc(size);
	va_start(args, format);
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
			if (spe->type == 'n')
			{
				free(specifiers);
				print_buffer(buffer);
				return (-1);
			}
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
	free(specifiers);
	return (print_buffer(buffer));
}
