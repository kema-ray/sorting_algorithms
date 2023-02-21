#include "sort.h"

/**
  * insertion_sort_list -  sorts a doubly linked list of
  * integers in ascending order
  * @list: linked list to sort
  */

void insertion_sort_list(listint_t **list)
{
	int n;
	listint_t *temp;

	if (!list)
		return;
	temp = *list;
	while (temp)
	{
		while (temp)
		{
			if (temp->next)
			{
				if (temp->n > temp->next->n)
				{
					n = temp->n;
					*(int *)&temp->n = temp->next->n;
					*(int *)&temp->next->n = n;
					temp = *list;
					print_list(*list);
					break;
				}
			}
			temp = temp->next;
		}
	}
}
