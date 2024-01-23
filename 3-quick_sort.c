#include "sort.h"

/**
 * swap - function that swaps two array elements
 * @x: element of array
 * @y: element of array
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
  * lomuto - function for partitioning the array from a pivot
  * @array: the array to partition
  * @low_idx: the lowest index of the array
  * @high_idx: the high index of the array
  * @size: size of array.
  *
  * Return: the index of the pivot after partitioning
  */
int lomuto(int *array, int low_idx, int high_idx, size_t size)
{
	int pivot_value = array[high_idx];
	int i = low_idx;
	int j;

	for (j = low_idx; j < high_idx; j++)
	{
		if (array[j] < pivot_value)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[high_idx] < array[i])
	{
		swap(&array[i], &array[high_idx]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursion - function that carry out the recursion.
 * @array: array to be traversed.
 * @first: first element of array
 * @last: last element of array
 * @size: size of the array
 */
void quick_sort_recursion(int *array, int first, int last, size_t size)
{
	int pivot_idx;

	if (first < last)
	{
		pivot_idx = lomuto(array, first, last, size);

		quick_sort_recursion(array, first, pivot_idx - 1, size);
		quick_sort_recursion(array, pivot_idx + 1, last, size);
	}
}

/**
 * quick_sort - a function that sorts an array
 * in ascending order
 * @array: array to be traversed
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
