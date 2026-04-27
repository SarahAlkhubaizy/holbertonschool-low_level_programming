#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_value - Updates value if key already exists
 * @ht: The hash table
 * @key: The key to search for
 * @value: The new value
 *
 * Return: 1 if updated, 0 if key not found
 */
static int update_value(hash_table_t *ht, const char *key,
		const char *value, unsigned long int index)
{
	hash_node_t *current;
	char *new_value;

	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (-1);
			free(current->value);
			current->value = new_value;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: The hash table
 * @key: The key (cannot be empty string)
 * @value: The value associated with the key
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int index;
	int updated;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	updated = update_value(ht, key, value, index);
	if (updated == 1 || updated == -1)
		return (updated == 1 ? 1 : 0);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
