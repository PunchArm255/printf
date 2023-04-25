#include "main.h"

void set_zero(int *a);
int get_flags(char c, int *a);

/**
 * _printf - print the thing according to format
 * @format: the format duh
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int flags[3], size;
	va_list args;
	const char *s;
	int (*f)(va_list args, int *flags);

	s = format;
	if (!s || (s[0] == '%' && s[1] == ' ' && s[2] == '\0'))
		return (-1);

	va_start(args, format);
	size = 0, set_zero(flags);
	while (*s)
	{
		if (*s != '%')
			_putchar(*s), size++;
		else if (*s == '%')
		{
			s++;
			while (*s && get_flags(*s, flags))
				s++;
			if (!(*s))
				return (-1);
			f = print_arg(*s);
			if (f)
				size += f(args, flags);
			else
				size += 2;
		}
		s++, set_zero(flags);
	}
	_putchar(-1);
	va_end(args);
	return (size);
}

/**
  * get_flags - search for flags (+, space, #)
  * @c: character
  * @flags: array of flags
  * Return: 0 not found | 1 found
  */
int get_flags(char c, int *flags)
{
	if (c == '+')
	{
		flags[0] = 1;
		return (1);
	}
	else if (c == ' ')
	{
		flags[1] = 1;
		return (1);
	}
	else if (c == '#')
	{
		flags[2] = 1;
		return (1);
	}
	return (0);
}

/**
  * set_zero - set flags to zerow
  * @a: array of flags
  * Return: void
  */
void set_zero(int *a)
{
	a[0] = 0, a[1] = 0, a[2] = 0;
}
