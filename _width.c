#include "main.h"
#include <stdio.h>
#include <stdarg.h>


/**
 * get_width - "Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments."
 *
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int son_i;
	int width = 0;

	for (son_i = *i + 1; format[son_i] != '\0'; son_i++)
	{
		if (is_digit(format[son_i]))
		{
			width *= 10;
			width += format[son_i] - '0';
		}
		else if (format[son_i] == '*')
		{
			son_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = son_i - 1;

	return (width);
}


