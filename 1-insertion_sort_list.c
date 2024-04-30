#include "sort.h"

/**
 * swap_node - Swap 2 nodes listint_t doubly-linked list
 * @head: pointer to the head
 * @swap_n: 1st node to swap
 * @swap_v: 2nd node to swap
 */
void swap_node(listint_t **head, listint_t *swap_n, listint_t *swap_v)
{
	listint_t *tmp;

	if (head == NULL || *head == NULL || swap_n == NULL || swap_v == NULL
			|| swap_n == swap_v || swap_n->next != swap_v)
		return;

	tmp = swap_n->prev;
	swap_n->prev = swap_v;
	swap_n->next = swap_v->next;
	swap_v->prev = tmp;
	swap_v->next = swap_n;
	if (swap_n->next != NULL)
		swap_n->next->prev = swap_n;
	if (swap_v->prev != NULL)
		swap_v->prev->next = swap_v;

	if (*head == swap_n)
		*head = swap_v;
}

/**
 * insertion_sort_list - Sort integers of doubly linked lists
 *by inserting sorting algorthmin ascending order
 *
 * @list: Pointer to head of doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curry;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curry = (*list)->next;

	while (curry != NULL)
	{
		while (curry->prev != NULL && curry->n < curry->prev->n)
		{
			swap_node(list, curry->prev, curry);

			if (curry->prev == NULL)
				*list = curry;

			print_list(*list);
		}
		curry = curry->next;
	}
}
