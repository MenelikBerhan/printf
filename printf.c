#include "main.h"

/**
 * buffer_overflow - prints buffer content and resets count
 * @str: string and it's length
 * @buffer: buffer
 * @k: count
 * @l: how many buffers were printed
 * @m: no of uncopied chars
 */
void buffer_overflow(String str, char *buffer, int *k, int *l, int *m)
{
	int copied = BUFFER_SIZE - *k - 1;

	strncpy(buffer + *k, str.s, copied);
	*m = (str.len + (*k)) - BUFFER_SIZE;
	print_buffer(buffer);
	*k = 0;
	(*l)++;
	strcpy(buffer, str.s + copied);
}

/**
 * _printf - produces output according to a format
 * @format: format of which to print
 *
 * Return: no of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j = 0, k = 0, l = 0, m = 0;
	FMT *specifiers, *spe;
	FMT_FUNC printer;
	String str;
	char buffer[BUFFER_SIZE] = "\0";

	if (!format)
		return (-1);
	specifiers = get_specifiers(format);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			m = 0;
			spe = &specifiers[j++];
			printer = spe->printer;
			if (!printer)
			{
				buffer[k++] = format[i];
				continue;
			}
			str = printer(&args, spe);
			if (str.len + k >= BUFFER_SIZE - 1)
				buffer_overflow(str, buffer, &k, &l, &m);
			else
				strcpy(buffer + k, str.s);
			k += m ? ++m : str.len;
			i = spe->endidx - 1;
			free(str.s);
		}
		else
			buffer[k++] = format[i];
	}
	va_end(args);
	if (k > 0)
		print_buffer(buffer);
	free(specifiers);
	return (l * BUFFER_SIZE + k - l);
}
