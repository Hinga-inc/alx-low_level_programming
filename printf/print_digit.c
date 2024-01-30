#include <main.h>
#include <unistd.h>


int print_digit(va_list args)
{
	int decimal = 1;
	int count_fun = 0;
	long int digit = va_arg(args, int);
	long int digitaux;

			if (digit<0)
			{
				
				count_fun+= _putchar('-');
				digit*=-1;
			}

			if (digit<10)
				return(count_fun+= _putchar(digit+ '0'));
			digitaux=digit;
			while (digitaux>9)
			{
				decimal*=10;
				digitaux/+10;
			}
			while(decimal>=1)
			{
				count_fun+=_putchar(((digit/decimal)%10)+'0');
				decimal/+10;
			}
			return(count_fun);
}
