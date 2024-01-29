#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 * Return: void.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (gap = 1; gap < size / 3; gap = 3 * gap + 1)
	{
		;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
