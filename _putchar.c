#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char b[1024];
	static int bSize;

	if (c == -1 || bSize >= 1024)
	{
		write(1, &b, bSize);
		bSize = 0;
	}
	if (c != -1)
		b[bSize++] = c;
	return (1);
}
