#include "main.h"

/**
 * * flip_bits - Number of bits needed to flip to get from one number to other.
 * * @n: Number to be fliped to.
 * * @m: Number to be fliped to.
 * * Return: Number of bits needed to flip.
 * **/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
		unsigned long int number = 0, count = 0;

			number = n ^ m;
				while (number)
						{
									if (number & 1)
													count++;

											number >>= 1;
												}

					return (count);
}
