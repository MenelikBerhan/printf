# Print Project ALX_SE cohort 13

## Introduction

This project is an adaptation of the printf function in C. The goal of this project is to create a custom printf function that can handle multiple format specifiers, flags, and custom specifiers.

## Installation

To use this custom printf function, simply include the main.h header file and compile the project with your C compiler of choice.

```
#include "main.h"
```

## Usage

The custom printf function has the following prototype:

```
int _printf(const char *format, ...);
```

To use the function, simply call it with a format string and any additional arguments. The function will return the number of characters printed (excluding the null byte used to end output to strings).

The format string is composed of zero or more directives. The following conversion specifiers are supported:

- **_%c_** - prints a single character
- **_%s_** - prints a string
- **_%%_** - prints a percent sign
- **_%d_** or %i - prints a signed integer
- **_%u_** - prints an unsigned integer
- **_%o_** - prints an octal number
- **_%x_** or %X - prints a hexadecimal number
- **_%p_** - prints a pointer address
- **_%l_** or %h - specifies long or short argument for integer specifiers

The following flags are supported:

- **_+_** - prints a plus sign for positive numbers
- **_space_** - prints a space for positive numbers
- **_#_** - prints 0 or 0x prefix for octal and hexadecimal numbers
- **_0_** - pads the field with zeroes instead of spaces
- **_-_** - left-aligns the field instead of right-aligning it

In addition to the standard conversion specifiers and flags, the following custom specifiers are supported:

- **_%b_** - converts an unsigned integer to binary
- **_%S_** - prints a string with non-printable characters represented as \x followed by the ASCII code value in hexadecimal (upper case, always 2 characters)
- **_%r_** - prints a string in reverse order
- **_%R_** - prints a string in ROT13 encoding

The custom printf function also handles the fields width and precision for non-custom conversion specifiers.

## Examples

```
_printf("Hello, %s!\n", "world");
// Output: Hello, world!

_printf("The answer is %d.\n", 42);
// Output: The answer is 42.

_printf("%+d\n", 42);
// Output: +42

_printf("%04d\n", 42);
// Output: 0042

_printf("%#x\n", 42);
// Output: 0x2a

_printf("%b\n", 42);
// Output: 101010

_printf("%S\n", "Hello\tworld\n");
// Output: Hello\x09world\x0a

_printf("%r\n", "Hello, world!");
// Output: !dlrow ,olleH

_printf("%R\n", "Hello, world!");
// Output: Uryyb, jbeyq!
```

## Contributors

- [**Girma Eshete**](https://github.com/MenelikBerhan)
- **Toby Salau**
