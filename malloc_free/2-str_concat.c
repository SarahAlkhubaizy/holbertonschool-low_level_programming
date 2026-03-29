#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string, or NULL
 */
char *str_concat(char *s1, char *s2)
{
	char *new;
	int len1;
	int len2;
	int i;
	int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	new = malloc(len1 + len2 + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
