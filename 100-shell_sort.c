#include "sort.h"
/**
 * shell_sort - sorts an array of integers using Shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1;
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Find the largest interval less than size */
    while (interval < size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];

            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
                array[j] = array[j - interval];

            array[j] = temp;
        }

        interval = (interval - 1) / 3;
        print_array(array, size);
    }
}
