#include "sort.h"

/**
 * max_sort - find maximum value in array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_sort(int *array, int size)
{
	int supreme, b;

	for (supreme = array[0], b = 1; b < size; b++)
	{
		if (array[b] > supreme)
			supreme = array[b];
	}

	return (supreme);
}

/**
 * counting_sort - Sort array of integers in ascending order
 *                 by counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Print counting array.
 */
void counting_sort(int *array, size_t size)
{
	int *num, *sorted, supreme, a;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	supreme = max_sort(array, size);
	num = malloc(sizeof(int) * (supreme + 1));
	if (num == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (supreme + 1); a++)
		num[a] = 0;
	for (a = 0; a < (int)size; a++)
		num[array[a]] += 1;
	for (a = 0; a < (supreme + 1); a++)
		num[a] += num[a - 1];
	print_array(num, supreme + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[num[array[a]] - 1] = array[a];
		num[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(num);
}
