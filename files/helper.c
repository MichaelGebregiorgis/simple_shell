#include "header.h"
#include <string.h>

/**
 * snline - stripeNewLine
 * @str: Data type
 * Return: 0
 */
void snline(char *str)
{
	str[strcspn(str, "\n")] = '\0';
}
