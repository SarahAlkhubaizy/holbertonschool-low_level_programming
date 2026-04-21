#include "lists.h"
#include <stdlib.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to pointer to the head of the list
 * @str: string to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int i;
	char *dup;

	i = 0;
	while (str[i] != '\0')
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(dup);
		return (NULL);
	}
	new->str = dup;
	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}
