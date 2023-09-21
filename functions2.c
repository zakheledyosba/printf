#include "main.h"


/**
 * print_pointer -"Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	char c = 0, pad = ' ';

	int x = BUFSIZ - 2, length = 2, start_pad = 1;

	unsigned long _addrs;

	char map_to[] = "0123456789abcdef";

	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	_addrs = (unsigned long)addrs;

	while (_addrs > 0)

	{
		buffer[x--] = map_to[_addrs % 16];
		_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))

		pad = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;

	x++;

	return (write_pointer(buffer, x, length,
		width, flags, pad, c, start_pad));
}

/**
 * print_non_printable -"Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification"
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)

{
	int b = 0, offset = 0;

	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[b] != '\0')
	{
		if (is_printable(str[b]))
			buffer[b + offset] = str[b];
		else
			offset += append_hexa_code(str[b], buffer, b + offset);

		b++;
	}

	buffer[b + offset] = '\0';

	return (write(1, buffer, b + offset));
}

/**
 * print_reverse -"Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;

	int d, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (d = 0; str[d]; d++)
		;

	for (d = d - 1; d >= 0; d--)
	{
		char y = str[d];

		write(1, &y, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string -"Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	char m;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				m = out[j];
				write(1, &m, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			m = str[i];
			write(1, &m, 1);
			count++;
		}
	}
	return (count);
}
