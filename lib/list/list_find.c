/*
** EPITECH PROJECT, 2024
** list_find
** File description:
** Finds a node in a list and returns it
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

list_t *list_find(list_t const *begin,
    void const *data_ref, int (*cmp)())
{
    list_t *tmp;
    list_t *result = NULL;

    tmp = (list_t *)begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref) == 0) {
            result = tmp;
            break;
        }
        tmp = tmp->next;
    }
    return result;
}
