#include "sort.h"
#include <stddef.h>
#include <string.h>
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: the size of the array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t tmp;
	int tswap;

	if (size < 2)
	{
		return;
	}

	/*make sure the loop checks every number until entire list is sorted*/
	for (i = 0; i < size; i++)
	{
		tswap = 0;
		/*iterate through arra swapping items*/
		for (j = 0; j < size; j++)
		/* swap items if a number is greater than the next*/
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				tswap = 1;
				print_array(array, size);
			}
		}
		if (!tswap)
		{
			break;
		}
	}
}
