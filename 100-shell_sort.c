#include "sort.h"

/**
 * swap_int - Define swap of 2 integers array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
  */
void swap_int(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * shell_sort - Sorting array of integers
 * using the shell sort algorithm.
 * @array: Pointer to array.
 * @size: Size of array.
 *
 * Description: Use Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gaps, a, b;

	if (array == NULL || size < 2)
		return;

	for (gaps = 1; gaps <= size / 3;)
		gaps = gaps * 3 + 1;

	for (; gaps >= 1; gaps /= 3)
	{
		for (a = gaps; a < size; a++)
		{
			b = a;
			while (b >= gaps && array[b - gaps] > array[b])
			{
				swap_int(array + b, array + (b - gaps));
				b -= gaps;
			}
		}
		print_array(array, size);
	}
}
