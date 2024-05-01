#include "sort.h"

void swap_viney(int *a, int *b);
int lomuto_partition_scheme(int *array, size_t size, int down, int up);
void lomuto_sort(int *array, int down, int up, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap_viney - Swapping two integers in an array
 *
 * @a: 1st integer to swap
 * @b: 2nd integer to swap
 */
void swap_viney(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition_scheme - Order a subset of array using
 *                           the Lomuto partition scheme.
 * @array: Array of integers.
 * @size: Size of array.
 * @down: Starting index of subset to order.
 * @up: Ending index of subset to order.
 *
 * Return: Final partition index.
 */
int lomuto_partition_scheme(int *array, size_t size, int down, int up)
{
    int *pivot, over, under;

    pivot = array + up;
    for (over = under = down; under < up; under++)
    {
        if (array[under] < *pivot)
        {
            if (over < under)
            {
                swap_viney(array + under, array + over);
                print_array(array, size);
            }
            over++;
        }
    }

    if (array[over] > *pivot)
    {
        swap_viney(array + over, pivot);
        print_array(array, size);
    }

    return (over);
}

/**
 * lomuto_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm with the Lomuto partition scheme.
 *
 * @array: The array to be sorted.
 * @down: The lowest index of the partition to sort.
 * @up: The highest index of the partition to sort.
 * @size: The size of the array.
 */
void lomuto_sort(int *array, int down, int up, size_t size)
{
    int pivot;

    if (down < up)
    {
        pivot = lomuto_partition_scheme(array, size, down, up);
        lomuto_sort(array, down, pivot - 1, size);
        lomuto_sort(array, pivot + 1, up, size);
    }
}

/**
 * quick_sort - Sort array in ascending order
 *              with quick sort algorithm.
 *
 * @array: The sorted array.
 * @size: Size of array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, 0, size - 1, size);
}
