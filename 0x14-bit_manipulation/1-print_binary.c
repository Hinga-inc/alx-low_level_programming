#include "main.h"

/**
 *  * print_binary - Convert decimal 2 binary.
 *   * @n: Decimal to convert in binary
 *    */
void print_binary(unsigned long int n)
{
		int i, count = 0;
			unsigned long int n_c;

				for (i = 63; i >= 0; i--)
						{
									n_c = n >> i;

											if (n_c & 1)
														{
																		_putchar('1');
																					count++;
																							}
													else if (count)
																	_putchar('0');
														}
					if (!count)
								_putchar('0');
}
