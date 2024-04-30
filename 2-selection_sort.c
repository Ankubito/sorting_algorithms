#include "sort.h"

/**
 * swap_viney - Define Swap of 2 intgs array
 * @swap_n: 1st integ to the swap
 * @swap_v: 2nd integ to the swap
 */
void swap_viney(int *swap_n, int *swap_v)
{
    int temp;

    temp = *swap_n;
    *swap_n = *swap_v;
    *swap_v = temp;
}

/**
 * selection_sort - Sort array of integers
 * using sort algorthm selectio
 * 
 * @array: The sorted arrays
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, end_alx;

	for (a = 0; a < size - 1; a++)
	{
		end_alx = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[end_alx])
				end_alx = b;
		}

		if (end_alx != a)
		{
			swap_viney(array + a, array + end_alx);

			print_array(array, size);
		}
	}
}
