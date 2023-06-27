#include"main.h"
/**
 * g_size - Determine the size to cast the arguments
 * @format: formattd string
 * @j: list of arguments
 * Return: precision
 */
int g_size(const char *format, int *j)
{
	int cur_j = *j + 1;
	int size = 0;

	if (format[cur_j] == 'l')
		size = S_LONG;
	else if (format[cur_j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = cur_j - 1;
	else
		*j = cur_j;
	return (size);
}
