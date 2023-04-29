#include "main.h"

/**
 * int_type - gets the right argument with right type
 * @args: variadic argument list
 * @fmt: specifier details
 *
 * Return: the int value
 */
Int int_type(va_list *args, FMT *fmt)
{
	Int num;
	int64_t temp;

	if (fmt->ex_type == 'l')
		temp = va_arg(*args, long);
	else if (fmt->ex_type == 's')
		temp = (short)va_arg(*args, int);
	else
		temp = va_arg(*args, int);
	num.neg = temp < 0;
	num.n = num.neg ? -temp : temp;
	return (num);
}
