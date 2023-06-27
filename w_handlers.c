#include"main.h"
/**
 * hand_write_char - print string
 * @c: char types
 * @buff: buffer array
 * @flags: active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: printed char
 */
int hand_write_char(char c, char buff[],
		int flags, int width, int precision, int size)
{
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buff[j++] = c;
	buff[j] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buff[BUFF_SIZE - j - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - j - 1], width - 1));
		else
		return (write(1, &buff[BUFF_SIZE - j - 1], width - 1) +
				write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 * write_numb - strings
 * @is_positive: list of args
 * @ind: char types
 * @buff: array
 * @flags: active flags
 * @width: width
 * @precision: specifier
 * @size: size specifier
 * Return: numbers of char printed
 */
int write_numb(int is_positive, int ind, char buff[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_positive)
		extra_c = '-';
	else if (flags & F_PLUS)
		extra_c = '+';
	else if (flags & F_SPACE)
		extra_c = ' ';
	return (numb(ind, buff, flags, width, precision,
				len, padd, extra_c));
}
/**
 * numb - write number using a buffer
 * @ind : index
 * @buff: Buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @length: number Length
 * @padd: padd
 * @extra_c: extra char
 * Return: Number of printed char
 */
int numb(int ind, char buff[],
		int flags, int width, int precision,
		int length, char padd, char extra_c)
{
	int j, p_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision < length)
		buff[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 0; j < width - length + 1; j++)
			buff[j] = padd;
		buff[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], j - 1) + write(1, &buff[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--p_start] = extra_c;
			return (write(1, &buff[p_start], j - p_start) +
					write(1, &buff[ind], length - (1 - p_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], length));
}
/**
 * pointer - Writea memory address
 * @buff: array
 * @ind: index
 * @length: length of numbers
 * @width: width
 * @flags: flags
 * @padd: represent padding
 * @extra_c: extra char
 * @padd_star: index at which padding should start
 * Return: Number
 */
int pointer(char buff[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_star)
{
	int j;

	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buff[j] = padd;
		buff[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], j - 3) + write(1, &buff[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_star] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_star], j - padd_star) +
					write(1, &buff[ind], length - (1 - padd_star) - 2));
		}
	}
		buff[--ind] = 'x';
		buff[--ind] = '0';
		if (extra_c)
			buff[--ind] = extra_c;
		return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
/**
 * usgnd - usigned number
 * @is_negative: sign indicator
 * @ind: index
 * @buff: array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: numbers of written char
 */
int usgnd(int is_negative, int ind, char buff[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, j = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buff[--ind] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > len)
	{
		for (j = 0; j < width - len;  j++)
			buff[j] = padd;
		buff[j] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], j));
		}
		else
		{
			return (write(1, &buff[0], j) + write(1, &buff[ind], len));
		}
	}
	return (write(1, &buff[ind], len));
}
