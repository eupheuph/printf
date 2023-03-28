#include "main.h"

/**
 * _putchar - prints/writes character
 * @character: The character to print
 * Return: 1, success, -1 error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
