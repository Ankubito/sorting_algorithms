#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>


/* define macros for Comparison direction bitonic sort */
enum ComparisonDirection {
UP = 0,
DOWN = 1
};

/**
 * enum bool - define Boolean values by enumeration.
 * @false: define 0.
 * @true: define 1.
 */
typedef enum {
	false = 0, /**< Represents bool value 'false', equivalent to 0. */
	true       /**< Represents bool value 'true', equivalent to 1. */
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* define the help Printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sort the algorithm functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
