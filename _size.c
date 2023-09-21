#include "main.h"
#include <stdio.h>


/**
 * get_precision -" Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments."
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)

{
	int pq_i = *i + 1;
	int precision = -1;

	if (format[pq_i] != '.')
		return (precision);

	precision = 0;

	for (pq_i += 1; format[pq_i] != '\0'; pq_i++)
	{
		if (is_digit(format[pq_i]))
		{
			precision *= 10;
			precision += format[pq_i] - '0';
		}
		else if (format[pq_i] == '*')
		{
			pq_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = pq_i - 1;

	return (precision);
}

