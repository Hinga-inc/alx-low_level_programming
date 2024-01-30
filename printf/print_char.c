#include <main.h>
#include <unistd.h>

int print_char(va_list args)
{
	char c=va_arg(args, int);
	_putchar(c);
	return(1);
}
