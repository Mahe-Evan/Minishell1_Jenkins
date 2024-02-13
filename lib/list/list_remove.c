/*
** EPITECH PROJECT, 2024
** list_remove
** File description:
** Removes a node from a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

static void list_remove_element(list_t **begin, list_t *tmp, list_t *prev)
{
    if (prev != NULL){
        prev->next = tmp->next;
    } else {
        *begin = tmp->next;
    }
}

void list_remove(list_t **begin,
    void const *ref, int (*cmp)())
{
    list_t *tmp = *begin;
    list_t *prev = NULL;

    while (tmp != NULL) {
        if ((*cmp)(tmp->data, ref)) {
            list_remove_element(begin, tmp, prev);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
