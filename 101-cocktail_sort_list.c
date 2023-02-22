#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 *                       the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *node = *list;

    if (list == NULL || node == NULL || node->next == NULL)
        return;

    do {
        swapped = 0;

        /* Traverse the list from left to right */
        while (node->next != NULL) {
            if (node->n > node->next->n) {
                swap_nodes(list, node, node->next);
                print_list(*list);
                swapped = 1;
            } else {
                node = node->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Traverse the list from right to left */
        while (node->prev != NULL) {
            if (node->n < node->prev->n) {
                swap_nodes(list, node->prev, node);
                print_list(*list);
                swapped = 1;
            } else {
                node = node->prev;
            }
        }

    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev1 = node1->prev;
    listint_t *prev2 = node2->prev;
    listint_t *next1 = node1->next;
    listint_t *next2 = node2->next;

    if (prev1 != NULL)
        prev1->next = node2;
    else
        *list = node2;

    if (next2 != NULL)
        next2->prev = node1;

    node1->next = next2;
    node1->prev = node2;
    node2->next = node1;
    node2->prev = prev1;

    if (prev2 != NULL)
        prev2->next = node1;

    if (next1 != NULL)
        next1->prev = node2;
}

/**
 * print_list - Prints a doubly linked list of integers
 *
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
    while (list != NULL) {
        printf("%d", list->n);
        list = list->next;
        if (list != NULL)
            printf(", ");
    }
    printf("\n");
}
