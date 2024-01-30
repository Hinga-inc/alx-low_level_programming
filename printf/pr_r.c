#include <main.h>
int print_rev_string(va_list args){
	int count_fun=0, i=0;
	char *s=va_arg(args, cahr *);

	if (!s)
		s="(null)";
	while(s[i])
	{
		i++;
	}
	while(i>=0)
	{
		count_fun+= _putchar(s[i]);
		i--;
	}
	count_fun--;
	return (count_fun);
}
