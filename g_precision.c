#include"main.h"
/**
 * g_precision - determine the pecision for printing
 * @format: formatted string to print arguement
 * @j: list of argument to be printed
 * @args: list of arguments
 * Return: precision
 */
int g_precision(const char *format, int *j, va_list args)
{
	int cur_j = *j + 1;
	int precision = -1;

	if (format[cur_j] != ' ')
		return (precision);
	precision = 0;

	for (cur_j += 1; format[cur_j] != '\0'; cur_j++)
	{
		if (is_digit(format[cur_j]))
		{
			precision *= 10;
			precision += format[cur_j] - '0';
		}
		else if (format[cur_j] == '*')
		{
			cur_j++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*j = cur_j - 1;
	return (precision);
}
