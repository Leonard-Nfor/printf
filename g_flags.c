#include"main.h"
/**
 * g_flags - determine active flags
 * @format: Formatted string argument
 * @j: Take a parameter
 * Return: flags
 */
int g_flags(const char *format, int *j)
{
	int k, cur_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const char FLAGS_ARR[] = { F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_j = *j + 1; format[cur_j] != '\0'; cur_j++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[cur_j] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}
		if (FLAGS_CH[k] == 0)
			break;
	}
	*j = cur_j - 1;
	return (flags);
}
