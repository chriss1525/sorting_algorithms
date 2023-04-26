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

    for (i = 0; i < (int)(size - 1); i++)
    {
        min_idx = i;
        for (j = i + 1; j < (int)(size); j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        swap(&array[min_idx], &array[i]);
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
