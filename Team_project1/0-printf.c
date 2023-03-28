#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed++;
			format++;
		}
		else
		{
			format++;
			printed = selector(format, args, printed);
			format++;
		}
	}
	va_end(args);
	return (printed);
}
