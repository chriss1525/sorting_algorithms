#include "sort.h"
/**
 * quick_sort -  sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of an array
 *
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	int pivot;
	int i;
	int j;

	if (size < 2)
		return;

	pivot = array[size / 2];

	for (i = 0, j = size - 1;; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i >= j)
			break;

		swap(&array[i], &array[j]);
		print_array(array, size);
	}

	if (i == size / 2 && j == size / 2 - 1)
	{
		quick_sort(array, size / 2);
		quick_sort(array + size / 2, size / 2);
	}
	else
	{
		quick_sort(array, i);
		quick_sort(array + i, size - i);
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
