#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: va_list
 */
static void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 * @args: va_list
 */
static void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: va_list
 */
static void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_str - prints a string
 * @args: va_list
 */
static void print_str(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	printf("%s", str ? str : "(nil)");
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 * @...: the arguments to print
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	unsigned int printed;
	unsigned int j;
	void (*funcs[4])(va_list);
	char keys[4];

	keys[0] = 'c';
	keys[1] = 'i';
	keys[2] = 'f';
	keys[3] = 's';
	funcs[0] = print_char;
	funcs[1] = print_int;
	funcs[2] = print_float;
	funcs[3] = print_str;
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == keys[j])
			{
				if (printed)
					printf(", ");
				funcs[j](args);
				printed++;
				break;
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
