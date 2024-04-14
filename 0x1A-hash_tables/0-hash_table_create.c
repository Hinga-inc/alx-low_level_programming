#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: the size, in number of nodes, to make the new hash table.
 *
 * Return: a pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{

	hash_table_t *h_t = NULL;
	hash_node_t **h_a = NULL;

	h_a = calloc(size, sizeof(char *));
	if (h_a == NULL)
	{
		free(h_a);
		return (NULL);
	}

	h_t = calloc(1, sizeof(hash_table_t));
	if (h_t == NULL)
		return (NULL);

	h_t->size = size;
	h_t->array = h_a;
	return (h_t);
}
