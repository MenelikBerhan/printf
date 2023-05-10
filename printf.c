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
	*m = str.len - copied;

	print_buffer(buffer, BUFFER_SIZE - 1);
	*k = 0;
	(*l)++;

	strcpy(buffer, str.s + copied);
}

/**
 * null_printer - handles exceptions with no printer function
 * @spe: apointer to FMT type
 * @format: format string
 * @buffer: buffer
 * @i: currrent @format index
 * @k: current @buffer index
 * @l: number of buffer prints
 *
 * Return: 0 if Successul or 1 if failure.
 */
int null_printer(FMT *spe, const char *format, char *buffer, int *i
					, int *k, int *l)
{
	int m = 0;
	String str;

	if (!spe->type)
	{
		print_buffer(buffer, *k);
		return (1);
	}

	str.len = spe->i_plus ? 2 : 1;
	str.s = malloc(sizeof(char) * (str.len + 1));
	if (!str.s)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	str.s[0] = format[*i];
	str.s[1] = spe->i_plus ? ' ' : '\0';

	if (*k  + str.len > BUFFER_SIZE - 1)
		buffer_overflow(str, buffer, k, l, &m);
	else
		strncpy(buffer + *k, str.s, str.len);

	*k += m ? m : str.len;
	*i = spe->endidx - 2;

	free(str.s);
	return (0);
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
				if (null_printer(spe, format, buffer, &i, &k, &l))
				{
					free(specifiers);
					va_end(args);
					return (-1);
				}
				continue;
			}
			str = printer(&args, spe);

			if (str.len > BUFFER_SIZE - 1 - k)
				buffer_overflow(str, buffer, &k, &l, &m);
			else
				strncpy(buffer + k, str.s, str.len);
			k += m ? m : str.len;
			i = spe->endidx - 1;
			free(str.s);
		}
		else
		{
			if (k >= BUFFER_SIZE - 1)
			{
				print_buffer(buffer, BUFFER_SIZE - 1);
				k = 0;
				l++;
			}
			buffer[k++] = format[i];
		}
	}
	va_end(args);
	if (k > 0)
		print_buffer(buffer, k);
	free(specifiers);
	return (l * (BUFFER_SIZE - 1) + k);
}
