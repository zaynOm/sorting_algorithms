#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 * @list: doubly linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *left, *right;

	if (!list || !(*list) || !(*list)->next)
		return;

	right = (*list)->next;
	while (right)
	{
		while (right->prev && right->prev->n > right->n)
		{
			left = right->prev;
			if (left->prev)
				left->prev->next = right;
			right->prev = left->prev;
			left->prev = right;
			left->next = right->next;
			if (right->next)
				right->next->prev = left;
			right->next = left;

			if (!right->prev)
				*list = right;
			print_list(*list);
		}
		right = right->next;
	}
}
