#include "sort.h"
#include <stdio.h>
/**
 *current_node - node swaps to the previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node
 */
listint_t *current_node(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *present = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	prev->next = present->next;
	if (present->next)
		present->next->prev = prev;
	present->next = prev;
	present->prev = prev->prev;
	prev->prev = present;
	if (present->prev)
		present->prev->next = present;
	else
		*list = present;
	return (present);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = current_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = current_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
