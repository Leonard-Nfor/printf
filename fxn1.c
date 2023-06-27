#include"main.h"
/**
 * p_unsigned_int  - print an usigned number
 * @args: args list
 * @buff: Buff array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number
 */
int p_unsigned_int(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = con_size_unsgnd(num, size);

	if (num == 0)
		buff[j--] = '0';
	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[j--] = (num % 10) + '0';
		num /= 10;
	}
	j++;
	return (unsgnd(0, j, buff, flags, width, precision, size));
}
/**
 * p_octal_num - print an unsigned number in octal nam
 * @args: args list
 * @buff: buffer array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number
 */
int p_octal_num(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int in_num = num;

	UNUSED(width);

	num = con_size_unsgnd(num, size);

	if (num == 0)
		buff[j--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && in_num != 0)
		buff[j--] = '0';
	j++;

	return (unsgnd(0, j, buff, flags, width, precision, size));
}
/**
 * P_hexaldecimal_num - print unsignd num
 * @args: args
 * @buff: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number
 */
int p_hexaldecimal_num(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(args, "0123456789abcdef", buff,
		flags,  'x', width, precision, size));
}
/**
 * p_hexa_uppercase - print an usigned int
 * @args: args list
 * @buff: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size; size
 * Return: Number
 */
int p_hexa_uppercase(va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	return (p_hexa(args, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}
/**
 * P_hexa - print hexa decimal
 * @args: list of args
 * @@map_to: array
 * @buff: buffer
 * @flags; flags
 * @flag_ch: active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: Number
 */
int p_hexa(va_list args, char map_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int in_num = num;

	UNUSED(width);

	num = con_size_unsgnd(num, size);

	if (num == 0)
		buff[j--] = '0';
	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && in_num != 0)
	{
		buff[j--] = flag_ch;
		buff[j--] = '0';
	}
	j++;

	return (unsgnd(0, j, buff, flags, width, precision, size));
}

