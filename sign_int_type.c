#include "main.h"

/**
 * sign_int_type - gets the right argument with right type
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the int value
 */
uint64_t sign_int_type(va_list *args, FMT *fmt)
{
	uint64_t num;

	if (fmt->ex_type == 'l')
		num = va_arg(*args, unsigned long);
	else if (fmt->ex_type == 'h')
		num = (unsigned short)va_arg(*args, unsigned int);
	else
		num = va_arg(*args, unsigned int);
	return (num);
}
