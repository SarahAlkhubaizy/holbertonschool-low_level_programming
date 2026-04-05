#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: the array to search
 * @size: the number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of first matching element, or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
