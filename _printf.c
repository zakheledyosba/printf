#include "main.h"
#include <stdio.h>
#include <stdarg.h>


void print_buffer(char buffer[], int *buff_ind);


/**
 * _printf - Printf function
 * @format: format.
 * by Sonto and Zakhele
 * Return: Printed chars
 *
 */
/*
 * _printf -"Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters"
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)

{

	int s = 0, print = 0, count = 0;

	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];

	if (*format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	for (; *format[s] != '\0'; s++)

	{
		if (*format[s] != '%')
		{
			format[s] = buffer[buff_ind++];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
			count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
=======
			flags = get_flags(format, &s);
			width = get_width(format, &s, list);
			precision = get_precision(format, &s, list);
			size = get_size(format, &s);
			++s;
			print = handle_print(format, &s, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			count += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - "Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length."

	return (count);
}

/
 * print_buffer -Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

