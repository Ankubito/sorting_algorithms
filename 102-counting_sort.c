#include "sort.h"

/**
 * fetch_max - find maximum value in array of integers.
 *
 * @array: Pointer to an array of integers.
 * @size: Size of the array
 *
 * Return: Maximum num of integers
 */
int fetch_max(int *array, int size)
{
	int maximum, b;

	for (maximum = array[0], b = 1; b < size; b++)
	{
		if (array[b] > maximum)
			maximum = array[b];
	}

	return (maximum);
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
	int *countin, *sorted, maximum, a;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = fetch_max(array, size);
	countin = malloc(sizeof(int) * (maximum + 1));
	if (countin == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (maximum + 1); a++)
		countin[a] = 0;
	for (a = 0; a < (int)size; a++)
		countin[array[a]] += 1;
	for (a = 0; a < (maximum + 1); a++)
		countin[a] += countin[a - 1];
	print_array(countin, maximum + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[countin[array[a]] - 1] = array[a];
		countin[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(countin);
}
