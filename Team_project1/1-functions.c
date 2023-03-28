#include "main.h"

/**
 * print_int - functions name
 * @types: lists of arguments
 * @buffer: array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size
 * Return: num of chars printed
 */

int print_int(va_list types, char buffer[], int flags,
	       	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - function name
 * @types: lists of arguments
 * @buffer: array to handle print
 * @flags: calculate active flags
 * @width: width
 * @precision: precision spec
 * @size: size
 * Return: num of chars printed
 */

int print_binary(va_list types, char buffer[], int flags,
	       	int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int z[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	z[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		z[i] = (n / m) % 2;
	}
	for (1 = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += z[i];

		if (sum || i == 31)
		{
			char a = '0' + z[i];

			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
