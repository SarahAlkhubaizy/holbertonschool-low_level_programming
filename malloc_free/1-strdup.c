#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a duplicated string
 * @str: the string to duplicate
 *
 * Return: pointer to the new string, or NULL
 */
char *_strdup(char *str)
{
	char *new;
	int len;
	int i;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
