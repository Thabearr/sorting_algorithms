#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start = *list, *end, *tmp;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (end = start; end->next != NULL; end = end->next)
        {
            if (end->n > end->next->n)
            {
                if (end->prev != NULL)
                    end->prev->next = end->next;
                else
                    *list = end->next;
                end->next->prev = end->prev;
                end->prev = end->next;
                end->next = end->next->next;
                end->prev->next = end;
                if (end->next != NULL)
                    end->next->prev = end;
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (end = end->prev; end->prev != NULL; end = end->prev)
        {
            if (end->n < end->prev->n)
            {
                if (end->next != NULL)
                    end->next->prev = end->prev;
                else
                    tmp = end;
                end->prev->next = end->next;
                end->next = end->prev;
                end->prev = end->prev->prev;
                end->next->prev = end;
                if (end->prev != NULL)
                    end->prev->next = end;
                else
                    *list = end;
                swapped = 1;
                print_list(*list);
            }
        }
        start = tmp;
    }
}
/**
 * print_list - Prints a list of integers
 *
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
    const listint_t *node;

    node = list;
    while (node != NULL)
    {
        printf("%d", node->n);
        node = node->next;
        if (node != NULL)
            printf(", ");
    }
    printf("\n");
}
