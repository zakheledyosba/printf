#include "main.h"
#include <stdio.h>
#include <stdarg.h>


void print_buffer(char buffer[], int *buff_ind);

/*
 * _printf -"Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters"
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)

{

	int x = 0, print = 0, count = 0;

	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];

	if (*format == NULL)
		return (-1);

	va_start(list, format);

	for (; *format[x] != '\0'; x++)
	{
		if (*format[x] != '%')
		{
			format[x] = buffer[buff_ind++];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			print = handle_print(format, &x, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			count += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (count);
}

/**
 * print_buffer -"Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length."
 */

void print_buffer(char buffer[], int *buff_ind)

{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
