#include "sort.h"

/**
 * bubble_sort - a function for sorting and printing
 * items in ascending order using bbuble sorting
 * @array: the array containing the items
 * @size: the size of the array
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t m, n;

	if (array == NULL || size < 2)
		return;
	for (m = 0; m < size - 1; m++)
	{
		for (n = 0; n < size - m - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap = array[n];
				array[n] = array[n + 1];
				array[n + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
