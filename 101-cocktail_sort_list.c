#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = *list, *end = NULL, *curr;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    /* Get the last node in the list */
    end = *list;
    while (end->next != NULL)
        end = end->next;

    while (swapped)
    {
        swapped = 0;

        /* Pass from start to end */
        curr = start;
        while (curr != end)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(list, curr, curr->next);
                swapped = 1;
            }
            else
            {
                curr = curr->next;
            }
        }
        end = curr;

        if (!swapped)
            break;

        swapped = 0;

        /* Pass from end to start */
        curr = end->prev;
        while (curr != start->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(list, curr->prev, curr);
                swapped = 1;
            }
            else
            {
                curr = curr->prev;
            }
        }
        start = curr->next;
    }
}

/**
 * swap_nodes - swaps nodes
 * @list: head node
 * @a: node a
 * @b: node b
 * Return: nothing
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{

    listint_t *prev_a = a->prev, *next_a = a->next, *prev_b = b->prev, *next_b = b->next;

    if (a == NULL || b == NULL)
        return;
    if (prev_a != NULL)
        prev_a->next = b;
    if (next_b != NULL)
        next_b->prev = a;

    a->prev = prev_b;
    b->next = next_a;
    b->prev = prev_a;
    a->next = next_b;

    if (*list == a)
        *list = b;
    else if (*list == b)
        *list = a;
}
