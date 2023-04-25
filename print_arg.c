#include "main.h"
#include <stdarg.h>

/**
 * print_arg - print argument corresponding to specifier
 * @c: specification
 * Return: void
 */
int (*print_arg(char c))(va_list, int *)
{
	sp list[] = {
		{'c', p_char},
		{'s', p_string},
		{'d', p_int},
		{'i', p_int},
		{'%', p_per},
		{'b', p_binary},
		{'u', p_unsigned},
		{'o', p_octal},
		{'x', p_lower_hex},
		{'X', p_upper_hex},
		{'p', p_pointer},
		{'S', p_String},
		{'r', p_rev},
		{'R', p_rot13}
	};
	int i;

	i = 0;
	while (i < 14)
	{
		if (c == list[i].c)
			return (list[i].f);
		i++;
	}
	_putchar('%');
	_putchar(c);
	return (0);
}
