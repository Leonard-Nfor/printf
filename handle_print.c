#include"main.h"
/**
 * handle_print - print args
 * @frm: formated string
 * @args: list of argument
 * @ind: index
 * @buff: buffer
 * @flags: active flags
 * @width: get width
 * @precision: get precision
 * @size: size specifier
 * Return: 1 or 2
 */
int handle_print(const char *frm, int *ind, va_list args,
		char buff[], int flags, int width, int precision, int size)
{
	int j, unknow_len = 0, p_char = -1;

	frm_t frm_types[] = {
		{'c', p_characters}, {'s', p_strings}, {'%', p_percentage},
		{'i', p_integer}, {'d', p_integer}, {'b', p_bin_num},
		{'u', p_unsigned_int}, {'0', p_octal_num}, {'x', p_hexaldecimal_num},
		{'X', p_hexa_uppercase}, {'p',p_address}, {'S', p_non_printchar},
		{'r', p_reverse}, {'R', p_rot13str}, {'\0', NULL}
	};
	for (j = 0; frm_types[j].frm != '\0'; j++)
		if (frm[*ind] == frm_types[j].frm)
			return (frm_types[j].fxn(args, buff, flags, width, precision, size));
	if (frm_types[j].frm == '\0')
	{
		if (frm[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (frm[*ind - 1] == ' ')
			unknow_len += write(1, "", 1);
		else if (width)
		{
			--(*ind);
			while (frm[*ind] != ' ' && frm[*ind] != '%')
				--(*ind);
			if (frm[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &frm[*ind], 1);
		return (unknow_len);
	}
	return (p_char);
}
