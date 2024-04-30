#include "sort.h"

/**
 * bubble_sort - sort array intergers with bubble algorith in ascending order
 * @array: Sorted arrays
 * @size: Size of arrays
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b, bubble_v;
	int swap_n;

	if (array == NULL || size < 2)
		return;

	b = size;
	while (b != 0)
	{
		bubble_v = 0;
		for (a = 1; a < b; a++)
		{
			if (array[a - 1] > array[a])
			{
				swap_n = array[a - 1];
				array[a - 1] = array[a];
				array[a] = swap_n;
				bubble_v = a;
				print_array(array, size);
			}
		}
		b = bubble_v;
	}
}
