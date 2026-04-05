#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 * @...: the arguments
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	int sep;
	char *str;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			if (sep)
				printf(", ");
			printf("%c", va_arg(args, int));
			sep = 1;
		}
		else if (format[i] == 'i')
		{
			if (sep)
				printf(", ");
			printf("%d", va_arg(args, int));
			sep = 1;
		}
		else if (format[i] == 'f')
		{
			if (sep)
				printf(", ");
			printf("%f", va_arg(args, double));
			sep = 1;
		}
		else if (format[i] == 's')
		{
			if (sep)
				printf(", ");
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
			sep = 1;
		}
		else
			va_arg(args, int);
		i++;
	}
	printf("\n");
	va_end(args);
}
