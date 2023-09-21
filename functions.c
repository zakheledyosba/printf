#include "main.h"


/**
 * print_char -"Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier"
 *
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;

	x = va_arg(types, int);

	return (handle_write_char(x, buffer, flags, width, precision, size));
}

/**
 * print_string -"Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier"
 *
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)

{

	int length = 0;

	int b;

	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)

	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], length);
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			return (width);
		}
		else
		{

	for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			write(1, &s[0], length);
			return (width);
		}
	}

	return (write(1, s, length));
}

/**
 * print_percent -"Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle pr
 * @width: get width.
 * @size:"
 * Return: number of chars
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int -"Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x;

	int is_negative = 0;

	long int m;

	unsigned long int digt;

	x = BUFSIZ - 2;
	m = va_arg(types, long int);

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	digt = (unsigned long int)m;

	if (m < 0)
	{
		digt = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (digt > 0)
	{
		buffer[x--] = (digt % 10) + '0';
		digt /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/**
 * print_binary -"Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, x, total;
	unsigned int a[32];
	int add;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (x = 1; x < 32; x++)
	{
		m /= 2;
		a[x] = (n / m) % 2;
	}
	for (x = 0, total = 0, add = 0; x < 32; x++)
	{
		total += a[x];
		if (total || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			add++;
		}
	}
	return (add);
}
