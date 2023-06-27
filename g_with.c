#include"main.h"
/**
 * g_width - determine the width
 * @format: format a string
 * @j: list of arguments
 * @args: list of arguments
 * Return: width
 */
int g_width(const char *format, int *j, va_list args)
{
	int cur_j;
	int width = 0;

	for (cur_j = *j + 1; format[cur_j] != '\0'; cur_j++)
	{
		if (is_digit(format[cur_j]))
		{
			width *= 10;
			width += format[cur_j] - '0';
		}
		else if (format[cur_j] == '*')
		{
			cur_j++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*j = cur_j - 1;
	return (width);
}
