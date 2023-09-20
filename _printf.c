#include "main.h"
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
