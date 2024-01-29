#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format - struct for format 
 * specifiers struct format
 * f the function associated
 */
typedef struct specifiers
{
	char specifiers;
	int (*f)(va_list);
}
specifiers_t;
/*prototypes*/
int _printf(const char *format, ...);
int get_funtion(char s, va_list args);
int _putchar(cahr c);

/*conversion specifiers*/
int print_char(va_list args);
int print_string(va_list args);
int print_digit(va_list args);
int print_mod(va_list args);
int print_rev_string(va_list args);

#endif
