#include "monty.h"
/**
 * is_integer - Checks if a string represents a valid integer
 * @str: String to be checked
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_integer(const char *str)
{
	int i;
	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (str[i] == '\0');
}
