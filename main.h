#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * struct str_fmt - struct for a string and it's length
 * @s: the string
 * @len: @s length
 *
 * Description: This struct holds a string and it's length
 */
typedef struct str_fmt
{
	char *s;
	int len;
} String;

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
	struct str_fmt (*printer)(va_list *args, struct fmt *fmt);
} FMT;

typedef struct str_fmt (*FMT_FUNC)(va_list *args, FMT *fmt);

int _printf(const char *format, ...);
FMT *get_specifiers(const char *str);
String int_fmt(va_list *args, FMT *fmt);
String sign_int_fmt(va_list *args, FMT *fmt);
String printable_str(va_list *args, FMT *fmt);
String pointer_fmt(va_list *args, FMT *fmt);
String hex_fmt(va_list *args, FMT *fmt);
String char_fmt(va_list *args, FMT *fmt);
String str_fmt(va_list *args, FMT *fmt);
String prcnt_fmt(va_list *args, FMT *fmt);
String rev_fmt(va_list *args, FMT *fmt);
String rot13_fmt(va_list *args, FMT *fmt);
String oct_fmt(va_list *args, FMT *fmt);
String bin_fmt(va_list *args, FMT *fmt);
void base_convert(long n, int base, int hex_cap, int neg, int *i, char **res);
int p_w_int(int i, int n, FMT *fmt, char **num);
void print_buffer(char *str);

#endif /* MAIN_H */
