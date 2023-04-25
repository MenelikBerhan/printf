#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format of which to print
 *
 * Return: no of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args = NULL;
	int i, j = 0, k = 0, size = BUFFER_SIZE;
	FMT *specifiers = get_specifiers(format), *spe;
	FMT_FUNC printer;
	char *buffer = malloc(size);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (k >= size - 1)
		{
			size *= 2;
			buffer = _realloc(buffer, size);
		}
		if (format[i] == '%')
		{
			char *str;

			spe = &specifiers[j++];
			printer = spe->printer;
			str = printer(args, spe);
			_strcpy(buffer + k, str);
			k += _strlen(str);
			i = spe->endidx - 1;
			free(str);
		}
		else
			buffer[k++] = format[i];
	}
	va_end(args);
	return (print_buffer(buffer));
}
