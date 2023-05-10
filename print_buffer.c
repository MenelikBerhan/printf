#include "main.h"

/**
 * print_buffer - prints a string using a buffer
 * @str: string to be printed
 * @len: length of string.
 */
void print_buffer(char *str, int len)
{
	int bytes_written;

	bytes_written = write(1, str, len);
	if (bytes_written != len)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	memset(str, '\0', len);
}
