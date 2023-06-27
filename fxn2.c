#include"main.h"
/**
 * pointer -  print the value of a pointer
 * @args: list of args
 * @buff: buffer
 * @flags: flags
 * @width: width
 * @precision:precision
 * @size: size
 * Return: number
 */
int p_address(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;

		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	ind++;
	return (pointer(buff, ind,
		len, width, flags, padd, extra_c, padd_start));
}
/**
 * p_non_printchar - prints ascii in hexa
 * @args: args
 * @buff: buff
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_non_printchar(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[j] != '\0')
	{
		if (printable(str[j]))
			buff[j + offset] = str[j];
		else
			offset += app_hexa_code(str[j], buff, j + offset);
		j++;
	}
	buff[j + offset] = '\0';
	return (write(1, buff, j + offset));
}
/**
 * p_reverse - print reverse string
 * @args: args
 * @buff: Buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_reverse(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		for (j = j - 1; j >= 0; j--)
		{
			char z = str[j];

			write(1, &z, 1);

			count++;
		}
	return (count);
}
/**
 * p_rot13str - print string rot 13
 * @args: args
 * @buff: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_rot13str(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
