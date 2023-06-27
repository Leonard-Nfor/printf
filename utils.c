#include"main.h"
/**
 * printable - check if char s printable
 * @c: char to be check
 * Return: 1 for success and 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * app_hexa_code - append ascii code
 * @buff: array
 * @j: index
 * @ascii_code: ASCII CODE
 * Return: Always 3
 */
int app_hexa_code(char ascii_code, char buff[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buff[j++] = '\\';
	buff[j++] = 'X';

	buff[j++] = map_to[ascii_code / 16];
	buff[j] = map_to[ascii_code % 16];

	return (3);
}
/**
 * con_size_num - cast number to specified size
 * @num: casted num
 * @size: size to be casted
 * Return: casted num
 */
long int con_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * is_digit -check if a char is a digit
 * @c: char to check
 * Return: 1 success a 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * con_size_unsgnd - const num to specified size
 * @num: casted numb
 * @size: Number indicating types
 * Return: casted value
 */
long int con_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
