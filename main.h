#ifndef _MAIN_
#define _MAIN_

#include <stdarg.h>

/**
  * struct specifier - specify which type to print
  * @c: specification
  * @f: poiner to function to print corresponding type
  */
typedef struct specifier
{
	char c;
	int (*f)(va_list p, int *flags);
} sp;

int _putchar(char c);
int (*print_argument(char c))(va_list, int *);
int p_int(va_list p, int *flags);
int p_string(va_list p, int *flags);
int p_char(va_list p, int *flags);
int p_per(va_list p, int *flags);
int p_binary(va_list p, int *flags);
int p_unsigned(va_list p, int *flags);
int p_octal(va_list p, int *flags);
int p_lower_hex(va_list p, int *flags);
int p_upper_hex(va_list p, int *flags);
int p_pointer(va_list list, int *flags);
int p_String(va_list p, int *flags);
int p_rev(va_list p, int *flags);
int p_rot13(va_list p, int *flags);

int _printf(const char *format, ...);

#endif /* siro gha t9awdo */
