#include "main.h"

/**
 * print_buffer - prints a string using a buffer
 * @str: string to be printed
 *
 * Return: lenght of printed string
 */
int print_buffer(char *str)
{
	char buffer[BUFFER_SIZE];
	int i, bytes_written, bytes_to_write, len = _strlen(str);

	for (i = 0; i < len; i += BUFFER_SIZE)
	{
		bytes_to_write = (i + BUFFER_SIZE < len) ? BUFFER_SIZE : len - i;
		_memcpy(buffer, str + i, bytes_to_write);
		bytes_written = write(1, buffer, bytes_to_write);
		if (bytes_written != bytes_to_write)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	_memset(str, '\0', len);
	free(str);
	return (len);
}
