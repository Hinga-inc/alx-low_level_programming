#include "hash_tables.h"


unsigned long int hash_djb2(const unsigned char * str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * hash_djb2 - hash function djb2 style
 * @str: key value
 *
 * Description: compute index with djb2 algorithm
 * Return: hash code
 */
