#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    int swapped = 1;
    listint_t *tmp;
    listint_t *head = *list;
    listint_t *tail = NULL;

    while (swapped) {
        swapped = 0;

        /* Traverse from left to right */
        for (tmp = head; tmp->next != tail; tmp = tmp->next) {
            if (tmp->n > tmp->next->n) {
                /* Swap nodes */
                if (tmp->prev != NULL)
                    tmp->prev->next = tmp->next;
                else
                    head = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp->prev = tmp->next;
                tmp->next = tmp->next->next;
                tmp->prev->next = tmp;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp;
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        tail = tmp;

        /* Traverse from right to left */
        for (tmp = tail->prev; tmp != NULL && tmp != head->prev;
             tmp = tmp->prev) {
            if (tmp->n > tmp->next->n) {
                /* Swap nodes */
                if (tmp->prev != NULL)
                    tmp->prev->next = tmp->next;
                else
                    head = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp->prev = tmp->next;
                tmp->next = tmp->next->next;
                tmp->prev->next = tmp;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp;
                swapped = 1;
                print_list(*list);
            }
        }
        head = head->next;
    }
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
