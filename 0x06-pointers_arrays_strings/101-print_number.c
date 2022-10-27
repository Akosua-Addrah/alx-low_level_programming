#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer
 */
void print_number(int n)
{
	unsigned int i = n, j;
	int power = 1;

	if (n < 0)
	{
		_putchar(45);
		i = -i;
	}

	j = i; /* i and j are copies of positive n */

	if (i > 0)
	{
		while (i / 10 > 0)
		{
			i /= 10;
			power *= 10;
		}
		while (power > 1)
		{
			_putchar((j / power) % 10 + 48);
			power /= 10;
		}
	}
	_putchar((j % 10) + 48);
}
