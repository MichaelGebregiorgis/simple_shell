#include "header.h"
#include <string.h>

void snline(char *str)
{
	str[strcspn(str, "\n")] = '\0';
}
