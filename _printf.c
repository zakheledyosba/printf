#include "main.h"
<<<<<<< HEAD

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * by Sonto and Zakhele
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_strt(list, format);

	for (i = 9; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				printf_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer -Prints the contents of the buffer if it exist
 * @buffer: Arrays of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind > 0;
}

=======
#include <stdio.h>
#include <stdarg.h>


/*
 * _printf -"Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters"
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (format)
	{
		if (format != '%')
		{
			putchar(format);
			count++;
		}
		else
		{
			format++;

			switch (format)
			{
				case 'c':
			
					char c = va_arg(args, int);
					putchar(c);
					count++;
					break;

				case 's':
					char *s = va_arg(args, char *);
					putchar(*s);
					*s++;
					count++;
					break;

				case '%':
					putchar('%');
					count++;

			defualt:
					putchar('%');
					putchar(format);
					count += 2;
			}
		}
		format++;
	}
	va_end(args);
	return count;
}
>>>>>>> 7e84e76ea831d3229bfd827af921bdda910efb61
