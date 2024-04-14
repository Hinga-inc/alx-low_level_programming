#include "hash_tables.h"


shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **ha;

	/** create a list of pointers of size and assign it to hash_table**/
	ha = calloc(size, sizeof(shash_node_t *));
	if (ha == NULL)
		return (NULL);

	/** create a hash_table and assign list of pointers to array **/
	ht = calloc(1, sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = ha;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *curr_old_node;

	if (key == NULL || ht == NULL)
		return (0);
/* set the item in the table */
	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];
	if (node == NULL)
		node = set_spair_only(ht, key, value, index);
	else
	{
		while (node != NULL)
		{
			if (strcmp(node->key, key) == 0)
				return (update_value(node, value));
			node = node->next;
		}
		node = set_spair_front(ht, key, value, index);
	}
	if (node == NULL)
		return (0);
/* arrange the item in the sorted linked list */
	if (ht->shead == NULL)
		return (slist_set_first(ht, node));
	curr_old_node = ht->shead;
	while (curr_old_node != NULL)
	{
		if (strcmp(curr_old_node->key, node->key) >= 0)
			return (slist_set(ht, curr_old_node, node));
		curr_old_node = curr_old_node->snext;
	}
	return (slist_set_end(ht, node));
}


int replace_node_value(shash_node_t *target, const char *value)
{
	/* free the target node's current value */
	/* strdup() the new value and set it in node */
	free(target->value);
	target->value = strdup(value);
	if (target->value == NULL)
		return (0);
	return (1);
}


int set_sorted_node(
	shash_node_t *node, shash_node_t **shead, shash_node_t **stail)
{
	shash_node_t *seeker = NULL;
	/* if shead empty, insert at head */
	if (*shead == NULL)
	{
		*shead = node;
		*stail = node;
		node->sprev = NULL;
		node->snext = NULL;
		/* printf("shead->key is %s\n", (*shead)->key); */
		/* printf("shead->value is %s\n", (*shead)->value); */

		return (1);
	}
	printf("*shead address is %p\n", (void*)*shead);
	/* else traverse list to find where value of new node fits */
	seeker = *shead;
	printf("seeker address is %p\n", (void*)seeker);
	while (seeker)
	{
		printf("got here\n");
		/* printf("shead->key is %s\n", (*shead)->key); */
		/* printf("shead->value is %s\n", (*shead)->value); */

		/* value inserted at head or in middle of ll */
		if (strcmp(seeker->value, node->value) < 0)
		{
			if (seeker == *shead)
			{
				/* printf("shead->key is %s\n", (*shead)->key); */
				/* printf("shead->value is %s\n", (*shead)->value); */

				node->snext = seeker;
				seeker->sprev = node;
				*shead = node;
				return (1);
			}
			else
			{
				node->snext = seeker;
				node->sprev = seeker->sprev;
				seeker->sprev = node;
				return (1);
			}
		}
		seeker = seeker->snext;
	}
	/* seeker is now last item in list */
	if (strcmp(seeker->value, node->value) < 0)
	{
		/* node inserted before seeker */
		node->snext = seeker;
		node->sprev = seeker->sprev;
		seeker->sprev = node;
		return (1);
	}
	else
	{
		/* node inserted after seeker and becomes tail */
		seeker->snext = node;
		node->sprev = seeker;
		node->snext = NULL;
		*stail = node;
		return (1);
	}
}


char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *seeker = NULL;

	/* check if caller passing admissable arguments */
	if (!ht || !key || !*key)
		return (NULL);

	/* check if shead */
	if (!ht->shead)
		return (NULL);

	seeker = ht->shead;
	/* loop sorted llist for matching key */
	while (seeker)
	{
		if (strcmp(seeker->key, key) == 0)
			return (seeker->value);
		seeker = seeker->next;
	}

	/* key not found */
	return (NULL);

}

/**
 * shash_table_print - function that prints a hash table
 * @ht: pointer to hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *seeker = NULL;

	/* check if ht is NULL return */
	if (!ht)
		return;

	printf("{");
	/* loop through indices of array for non-NULL */
	seeker = ht->shead;
	while (seeker)
	{
		printf("'%s': ", seeker->key);
		printf("'%s'", seeker->value);
		if (seeker->snext)
		{
			printf(", ");
			seeker = seeker->snext;
		}
		else
			break;
	}
	printf("}\n");


}

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node;

	while (i < ht->size)
	{
		while (ht->array[i] != NULL)
		{
			node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = node;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node = ht->stail;

	if (ht == NULL)
		return;
	printf("{");
	while (node != NULL)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		count++;
	}
	printf("}\n");
}
