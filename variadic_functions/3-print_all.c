#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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
	unsigned int i;
	int sep;
	char *str;
	char *types = "cifs";
	char *formats[] = {"%c", "%d", "%f", "%s"};

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = strchr(types, format[i]);
		if (str)
		{
			if (sep)
				printf(", ");
			if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				printf(s ? "%s" : "(nil)", s ? s : "(nil)");
			}
			else if (format[i] == 'f')
				printf(formats[str - types], va_arg(args, double));
			else
				printf(formats[str - types], va_arg(args, int));
			sep = 1;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
