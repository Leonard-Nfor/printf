#include"main.h"
/**
 * p_characters - print chars
 * @args: list of arguement
 * @buff: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number
 */
int p_characters(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(args, int);

	return (handle_write_char(b, buff, flags, width, precision, size));
}
/**
 * p_strings - prinst string
 * @args:list of args
 * @buff: buff array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_strings(va_list args, char buff[],
	 int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *s = va_arg(args, char *);

	UNUSED(buff);
	UNUSED(size);


	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s =  "      ";
	}
	while (s[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (j = width - len; j > 0; j--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, "", 1);
			write(1, &s[0], len);
			return (width);
		}
	}
	return (write(1, s, len));
}
/**
 * p_percent - print percentage sign
 * @args: list of args
 * @buff: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed
 */
int p_percentage(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
/**
 * p_integer - print integer
 * @args: list of args
 * @buff: buffer of array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Numbers
 */
int p_integer(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(args, long int);
	unsigned long int number;

	m = con_size_num(m, size);

	if (m == 0)
		buff[j--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)m;

	if (m < 0)
	{
		number = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (number > 0)
	{
		buff[j--] = (number % 10) + '0';
		number /= 10;
	}
	j++;

	return (write_numb(is_negative, j, buff, flags, width, precision, size));
}
/**
 * p_bin_num - print unsigned  number
 * @args: args
 * @buff: buff
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_bin_num(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, j, sum;
	unsigned int b[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);


	n = va_arg(args, unsigned int);
	m = 2147483648;
	b[0] =  n / m;

	for (j = 1; j < 32; j++)
	{
		m /= 2;
		b[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += b[j];
		if (sum || j == 31)
		{
			char v = '0' + b[j];

			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
