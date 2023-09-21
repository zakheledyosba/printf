#include "main.h"


/**
 * print_unsigned -"Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 *
 * Return: Number of c printed.
 */

int print_unsigned(va_list types, char buffer[],int flags, int width, int precision, int size)
{

	int x;
	
	unsigned long int digt = va_arg(types, unsigned long int);

	x = BUFSIZ - 2;
	digt = convert_size_unsgnd(digt, size);

	if (digt == 0)
	{
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	}
	while (digt > 0)
	{
		buffer[x--] = (digt % 10) + '0';
		digt /= 10;
	}
	x++;
	return (print_unsigned(x, buffer, flags, width, precision, size));
}

/**
 * print_octal -"Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 * Return: Number of c printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x;

	unsigned long int digt;

	unsigned long int init_digt;

	x = BUFSIZ - 2;
	digt = va_arg(types, unsigned long int);
	init_digt = digt;

	UNUSED(width);

	digt = convert_size_unsgnd(digt, size);

	if (digt == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (digt > 0)
	{
		buffer[x--] = (digt % 8) + '0';
		digt /= 8;
	}

	if (flags & F_HASH && init_digt != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal -"Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 *
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)

{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper -"Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier"
 *
 * Return: Number of c printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)

{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa -"Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification"
 *
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)

{
	int x;

	unsigned long int digt;

	unsigned long int init_digt;

	x = BUFSIZ - 2;
	init_digt = digt;
	digt = va_arg(types, unsigned long int);

	UNUSED(width);

	digt = convert_size_unsgnd(digt, size);

	if (digt == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (x > 0)
	{
		buffer[x--] = map_to[digt % 16];
		digt /= 16;
	}

	if (flags & F_HASH && init_digt != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}
