#include"main.h"
void p_buff(char buffer[], int *buff_ind);
/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int j, p = 0, p_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;

	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				p_buff(buff, &buff_ind);
			p_char++;
		}
		else
		{
			p_buff(buff, &buff_ind);
			flags = g_flags(format, &j);
			width = g_width(format, &j, args);
			precision = g_precision(format, &j, args);
			size = g_size(format, &j);
			++j;
			p = handle_print(format, &j, args, buff,
					flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_char += p;
		}
	}
		p_buff(buff, &buff_ind);

		va_end(args);

		return (p_char);
}
/**
 * p_buff - print content of buffer
 * @buff: Arrray of chars
 * @buff_ind: index to addd next chars
 */
void p_buff(char buff[], int *buff_ind)
{
        if (*buff_ind > 0)
                write(1, &buff[0], *buff_ind);

         *buff_ind = 0;
}
