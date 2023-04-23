#include "sort.h"
#include <stddef.h>
#include <string.h>
/**
 *
 */

void bubble_sort(int *array, size_t size)
{
    size_t i;
    size_t j;
    size_t tmp;

    /*make sure the loop comes back until entire list is sorted*/
    for (i = 0; i < size; i++)
    {
        /*iterate through arra swapping items*/
        for (j = 0; j < size; j++)
        /* swap items if a number is greater than the next*/
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                print_array(array, size);
            }
        }
    }
}