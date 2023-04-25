#include "main.h"
#include <stdarg.h>

/**
  * p_binary - convert decimal into binary and print it
  * @p: pointer to list of arguments to get number
  * @flags: array of flags
  * Return: length of binary
  */
int p_binary(va_list p, __attribute__((unused)) int *flags)
{
	unsigned int n, size;
	int i;
	int arr[32];

	n = va_arg(p, int);
	if (!n)
	{
		_putchar('0');
		return (1);
	}
	size = 0;
	while (n > 0)
	{
		arr[size++] = n % 2;
		n /= 2;
	}
	for (i = size - 1; i >= 0; i--)
		_putchar(arr[i] + '0');

	return (size);
}

/**
  * p_unsigned - print unsigned integer
  * @p: pointer to list of arguments to get number
  * @flags: array of flags
  * Return: length of number
  */
int p_unsigned(va_list p, __attribute__((unused)) int *flags)
{
	unsigned int a, i, size;
	unsigned int arr[100];

	i = 99;
	a = va_arg(p, unsigned int);
	size = 0;
	while (a > 9)
	{
		arr[i--] = a % 10;
		a /= 10;
	}
	arr[i] = a;
	while (i < 100)
	{
		_putchar(arr[i++] + '0');
		size++;
	}
	return (size);
}

/**
  * p_octal - convert decimal to octal and print it
  * @p: pointer to argument list to get number
  * @flags: array of flags
  * Return: length of octal
  */
int p_octal(va_list p, int *flags)
{
	unsigned int n, size;
	unsigned int arr[100];
	int i, f;

	n = va_arg(p, unsigned int);
	if (!n)
	{
		_putchar('0');
		return (1);
	}
	size = 0, f = 0;
	if (flags[2])
		_putchar('0'), f++;
	while (n > 0)
	{
		arr[size++] = n % 8;
		n /= 8;
	}
	for (i = size - 1; i >= 0; i--)
		_putchar(arr[i] + '0');
	return (size + f);
}

/**
  * p_upper_hex - convert decimal to upper hexadecimal and print it
  * @p: pointer to argument list to get number
  * @flags: array of flags
  * Return: length of hexa
  */
int p_upper_hex(va_list p, int *flags)
{
	unsigned int n, size;
	unsigned int arr[100];
	int i, f;

	n = va_arg(p, unsigned int);
	if (!n)
	{
		_putchar('0');
		return (1);
	}
	size = 0, f = 0;
	if (flags[2])
		_putchar('0'), _putchar('X'), f += 2;
	while (n > 0)
	{
		arr[size++] = n % 16;
		n /= 16;
	}
	for (i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 10)
			_putchar(arr[i] + '0');
		else
			_putchar(arr[i] + '7');
	}
	return (size + f);
}

/**
  * p_lower_hex - convert decimal to lower hexadecimal and print it
  * @p: pointer to argument list to get number
  * @flags: array of flags
  * Return: length of hexa
  */
int p_lower_hex(va_list p, int *flags)
{
	unsigned int n, size;
	unsigned int arr[100];
	int i, f;

	n = va_arg(p, unsigned int);
	if (!n)
	{
		_putchar('0');
		return (1);
	}
	size = 0, f = 0;
	if (flags[2])
		_putchar('0'), _putchar('x'), f += 2;
	while (n > 0)
	{
		arr[size++] = n % 16;
		n /= 16;
	}
	for (i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 10)
			_putchar(arr[i] + '0');
		else
			_putchar(arr[i] + 'W');
	}
	return (size + f);
}
