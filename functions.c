#include "main.h"
#include <stdio.h>

/**
  * p_int - print integer
  * @args: pointer to list to get integer
  * @flags: array of flags
  * Return: digit count
  */
int p_int(va_list args, int *flags)
{
	int a, i, size, rem;
	int arr[100];

	i = 99;
	a = va_arg(args, int);
	size = 0;
	if (a < 0)
		_putchar('-'), size++;
	else if (flags[0])
		_putchar('+'), size++;
	else if (flags[1])
		_putchar(' '), size++;
	while (a > 9 || a < -9)
	{
		rem = a % 10;
		arr[i--] = (rem > 0) ? (rem) : (rem * (-1));
		a /= 10;
	}
	arr[i] = (a > 0) ? (a) : (a * (-1));
	while (i < 100)
	{
		_putchar(arr[i++] + '0');
		size++;
	}
	return (size);
}

/**
  * p_char - print character
  * @args: pointer to list to get integer
  * @flags: array of flags
  * Return: 1
  */
int p_char(va_list args,  __attribute__((unused)) int *flags)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
  * p_string - print string
  * @args: pointer to list to get string
  * @flags: array of flags
  * Return: string length
  */
int p_string(va_list args,  __attribute__((unused)) int *flags)
{
	int i;
	char *s;

	i = 0;
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
		_putchar(s[i++]);
	return (i);
}

/**
  * p_per - print % sign
  * @args: pointer to list
  * @flags: array of flags
  * Return: 1
  */
int p_per(__attribute__((unused)) va_list args, int *flags)
{
	int a;

	a = flags[0];
	if (a == 20)
		_printf("dummy");
	_putchar('%');
	return (1);
}
