#include <stdio.h>
#include "main.h"


/**
 * get_flags - "Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter."
 * Return: Flags
 */

int get_flags(const char *format, int *i);

{
	
	int b, 
	int cxrr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cxrr_i = *i + 1; format[cxrr_i] != '\0'; cxrr_i++)
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[cxrr_i] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*i = cxrr_i - 1;

	return (flags);
}

