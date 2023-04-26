#include "sort.h"
/**
 * selection_sort - sorts integers in ascending order
 * selction sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int j;
	int min_idx;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (int)(size - 1); i++)
	{
		min_idx = i;
		for (j = i + 1; j < (int)(size); j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			if (array[min_idx] != array[i])
			{
				swap(&array[min_idx], &array[i]);
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - swaps two integers
 * @a: integer
 * @b: integer
 *
 * Return:nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
