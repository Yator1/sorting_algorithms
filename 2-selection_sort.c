#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the arrays size
 *
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t m, n, min;
	int tmp;

	if (array == NULL || size <= 1)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = m;

		for (n = m + 1; n < size; n++)
		{
			if (array[n] < array[min])
			{
				min = n;
			}
		}
		if (min != m)
		{
			tmp = array[m];
			array[m] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
