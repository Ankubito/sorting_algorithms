#include "sort.h"
#include "stdbool.h"

void swap_node_high(listint_t **list, listint_t **end, listint_t **shiver);
void swap_node_low(listint_t **list, listint_t **end, listint_t **shiver);
void cocktail_sort_list(listint_t **list);
/**
 * swap_node_high - Swaps two adjacent nodes in the list when the current node
 *                  has a greater value than the next node.
 *
 * @list: Pointer to the pointer to the head of the list.
 * @end: Pointer to the pointer to the end of the list.
 * @shiver: Pointer to the pointer to the current node.
 */
void swap_node_high(listint_t **list, listint_t **end, listint_t **shiver)
{
	listint_t *tmp = (*shiver)->next;

	if ((*shiver)->prev != NULL)
		(*shiver)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shiver)->prev;
	(*shiver)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shiver;
	else
		*end = *shiver;
	(*shiver)->prev = tmp;
	tmp->next = *shiver;
	*shiver = tmp;
}
/**
 * swap_node_low - Swaps two adjacent nodes in the list when the current node
 *                 has a smaller value than the previous node.
 *
 * @list: Pointer to the pointer to the head of the list.
 * @end: Pointer to the pointer to the end of the list.
 * @shiver: Pointer to the pointer to the current node.
 */
void swap_node_low(listint_t **list, listint_t **end, listint_t **shiver)
{
	listint_t *tmp = (*shiver)->prev;

	if ((*shiver)->next != NULL)
		(*shiver)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*shiver)->next;
	(*shiver)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shiver;
	else
		*list = *shiver;
	(*shiver)->next = tmp;
	tmp->prev = *shiver;
	*shiver = tmp;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in non-decreasing order
 *                      using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to the pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *shiver;
	bool shiver_unstirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (shiver_unstirred == false)
	{
		shiver_unstirred = true;
		for (shiver = *list; shiver != end; shiver = shiver->next)
		{
			if (shiver->n > shiver->next->n)
			{
				swap_node_high(list, &end, &shiver);
				shiver_unstirred = false;
			}
		}
		for (shiver = shiver->prev; shiver != *list;
				shiver = shiver->prev)
		{
			if (shiver->n < shiver->prev->n)
			{
				swap_node_low(list, &end, &shiver);
				shiver_unstirred = false;
			}
		}
	}
}
