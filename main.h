#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct fmt - struct for format specifiers details
 * @type: data type of specifier
 * @ex_type: supporting type for ints (long or short)
 * @width: minimum width
 * @endidx: index of the next string char after the fmt has been read
 * @left: left justify
 * @dp: precision
 * @base_prefix: should there be a base prefix
 * @i_plus: should there be an invisible plus
 * @p_plus: should the plus be printed
 * @leading: leading char
 * @printer: function to handle formatting
 *
 * Description: This struct holds the details for each format speci
 */
typedef struct fmt
{
	char type;
	char ex_type;
	int width;
	int endidx;
	int left;
	int dp;
	int base_prefix;
	int i_plus;
	int p_plus;
	char leading;
	char *(*printer)(va_list args, struct fmt *fmt);
} FMT;
typedef char *(*FMT_FUNC)(va_list args, FMT *fmt);

int _printf(const char *format, ...);
FMT *get_specifiers(const char *str);
char *int_fmt(va_list args, FMT *fmt);
char *sign_int_fmt(va_list args, FMT *fmt);
char *printable_str(va_list args, FMT *fmt);
char *pointer_fmt(va_list args, FMT *fmt);
char *hex_fmt(va_list args, FMT *fmt);
char *char_fmt(va_list args, FMT *fmt);
char *str_fmt(va_list args, FMT *fmt);
char *prcnt_fmt(va_list args, FMT *fmt);
char *rev_fmt(va_list args, FMT *fmt);
char *rot13_fmt(va_list args, FMT *fmt);
char *oct_fmt(va_list args, FMT *fmt);
char *bin_fmt(va_list args, FMT *fmt);
void base_convert(long n, int base, int hex_cap, int neg, int *i, char **res);
int p_w_int(int i, int n, FMT *fmt, char **num);
int print_buffer(char *str);

#endif /* MAIN_H */
