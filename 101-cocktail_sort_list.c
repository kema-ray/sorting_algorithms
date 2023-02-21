#include "sort.h"

/**
  * swapme - swaps a node with the next node in the list
  * @list: double pointer to the beginning of the list
  * @node: node to swap
  */

void swapme(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
  * cocktail_sort_list - sorts a doubly linked list of integers in ascending
  * order using the Cocktail shaker sort algorithm
  * @list: doubly linked list
  */

void cocktail_sort_list(listint_t **list)
{
	char tmp = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (tmp != 0)
	{
		tmp = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swapme(list, temp);
				tmp = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (tmp == 0)
			break;
		tmp = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swapme(list, temp->prev);
				tmp = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
