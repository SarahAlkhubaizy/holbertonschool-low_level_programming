#include "main.h"

/**
 * helper - helper function to find square root
 * @n: the number
 * @i: current value to test
 *
 * Return: square root or -1
 */
int helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: square root of n, or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (helper(n, 0));
}
