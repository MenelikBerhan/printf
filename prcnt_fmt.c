#include "main.h"

/**
 * prcnt_fmt - creates a string "%" for %% conversion specification.
 * @args: variadic argument list
 * @fmt: An FMT type format specifier.
 *
 * Return: The string "%" if fmt->type = "%" or empty string otherwise.
 */
<<<<<<< HEAD
char *prcnt_fmt(va_list args, FMT *fmt)
=======

char *prcnt_fmt(void *data, FMT *fmt)
>>>>>>> a50225995137876b4370cc314d36f18a82020e60
{
	char *str = malloc(sizeof(char) * 2);
	(void)args;
	(void)fmt;

	str[0] = '%';
	str[1] = '\0';
	return (str);
}
