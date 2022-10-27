#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: number 1
 * @n2: number 2
 * @r: buffer that the function will use to store the result
 * @size_r: buffer size
 * Return: pointer to the result
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry_val = 0, i, j, k = 1, max, result;
	char buffer;

	for (i = 0; n1[i]; i++)
		;
	for (j = 0; n2[j]; j++)
		;
	if (i >= j)
		max = i;
	else
		max = j;
	if (size_r <= max)
		return (0);
	i--, j--;
	while (max-- > 0)
	{
		if (i >= 0 && j >= 0)	/* n1 and n2 still have values */
			result = (n1[i] - 48) + (n2[j] - 48) + carry_val;
		else if (i < 0 && j >= 0) /* n2 only */
			result = (n2[j] - 48) + carry_val;
		else if (i >= 0 && j < 0) /* n1 only */
			result = (n1[i] - 48) + carry_val;
		if (result > 9)
			r[k - 1] = (result % 10) + 48, carry_val = 1;
		else
			r[k - 1] = result + '0', carry_val = 0;
		i--, j--, k++, size_r--;
		if (size_r <= 1)
			return (0);
		if (i < 0 && j < 0)
			break;
	}
	if (result > 9 && size_r >= 0)
		r[k - 1] = '1', r[k] = '\0';
	for (i = 0; r[i]; i++)
		;
	for (j = 0; j < (i - 1) / 2; j++)
		buffer = r[j], r[j] = r[i - j - 1], r[i - j - 1] = buffer;
	return (r);
}
