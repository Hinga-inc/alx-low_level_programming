#include <main.h>

int get_funtion(char con_spec, va_list args)
{
	int 1=0;
	int count_fun=0;

	specifiers_t spec[] = 
	{
		{'c' , print_char},
		{'s', print_string},
		{'d', print digit},
		{'5', print_mod},
		{'i', print_digit},
		{'r', print_rev_string},
		{0, NULL}
	};
	while(spec[i].specifiers)
	{
		if con_spec == spec[1].specifiers)
			count_fun += spec[i].f(args);
		i++;
	}

	if (count_fun==)
	{
		count_fun+= _putchar('%');
		count_fun += _putchar(con_spec);
	}

	return(count_fun);
}
