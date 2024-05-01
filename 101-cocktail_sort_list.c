#ifndef SORT_H
#define SORT_H
#include <stdio.h> 

typedef struct listint_s {
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void swap_node_high(listint_t **list, listint_t **end, listint_t **shiver);
void swap_node_low(listint_t **list, listint_t **end, listint_t **shiver);
void cocktail_sort_list(listint_t **list);

#endif /* SORT_H */

#include "sort.h"
#include <stdbool.h>

void swap_node_high(listint_t **list, listint_t **end, listint_t **shiver) {
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

void swap_node_low(listint_t **list, listint_t **end, listint_t **shiver) {
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

void cocktail_sort_list(listint_t **list) {
    listint_t *end, *shiver;
    bool shiver_unstirred = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (end = *list; end->next != NULL;)
        end = end->next;

    while (!shiver_unstirred) {
        shiver_unstirred = true;
        for (shiver = *list; shiver != end; shiver = shiver->next) {
            if (shiver->n > shiver->next->n) {
                swap_node_high(list, &end, &shiver);
                print_list(*list);
                shiver_unstirred = false;
            }
        }
        for (shiver = shiver->prev; shiver != *list; shiver = shiver->prev) {
            if (shiver->n < shiver->prev->n) {
                swap_node_low(list, &end, &shiver);
                print_list(*list);
                shiver_unstirred = false;
            }
        }
    }
}
