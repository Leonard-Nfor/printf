#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct frm - struct frm
 * @frm: The format
 * @fxn: The function associate
 */
struct frm
{
	char frm;
	int (*fxn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frm frm_t - struct op
 * @frm: The format
 * @frm_t: The function associate
 */
typedef struct frm frm_t;
int _printf(const char *format, ...);
int handle_print(const char *frm, int *j,
	va_list args, char buff[], int flags, int width, int precision, int size);


/******FUNCTIONS NEEDED******/
/*Strings and characters*/

int p_characters(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_strings(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_percentage(va_list args, char buff[],
	int flags, int width, int precision, int size);

/*print numbers */

int p_integer(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_bin_num(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_unsigned_int(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_octal_num(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_hexaldecimal_num(va_list args, char buff[],
	int flags, int width, int precision, int size);
int p_hexa_uppercase(va_list args, char buff[],
	 int flags, int width, int precision, int size);
int p_hexa(va_list args, char map_to[], char buff[],
	 int flags, char flag_ch, int width, int precision, int size);

/*print non prinatable characters */

int p_non_printchar(va_list args, char buff[],
	 int flags, int width, int precision, int size);

/*print memory address */

int p_address(va_list args, char buff[],
	 int flags, int width, int precision, int size);

/* Handle other specifiers */

int g_flags(const char *format, int *j);
int g_width(const char *format, int *j, va_list args);
int g_precision(const char *format, int *j, va_list args);
int g_size(const char *format, int *j);

/*print string in reverse*/

int p_reverse(va_list args, char buff[],
	 int flags, int width, int precision, int size);

/*string in rot13*/

int p_rot13str(va_list args, char buff[],
	int flags, int width, int precision, int size);

/*Handle width */

int handle_write_char(char b, char buff[],
	int flags, int width, int precision, int size);
int write_numb(int is_positive, int ind, char buff[],
	int flags, int width, int precision, int size);
int numb(int ind, char bff[], int flags, int width,
	int precision, int length, char padd, char extra_c);
int pointer(char buff[], int ind, int length, int width,
	int flags, char padd, char extra_c, int padd_start);
int unsgnd(int is_negative, int ind, char buff[],
	int flags, int width, int precision, int size);

/**********UTILS********/

int printable(char);
int app_hexa_code(char, char[], int);
int is_digit(char);
long int con_size_num(long int num, int size);
long int con_size_unsgnd(unsigned long int num, int size);

#endif
