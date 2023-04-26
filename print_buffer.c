#include "main.h"

/**
 * print_buffer - prints a string using a buffer
 * @str: string to be printed
 */
void print_buffer(char *str)
{
	int bytes_written, len = strlen(str);

	bytes_written = write(1, str, len);
	if (bytes_written != len)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	memset(str, '\0', len);
}
