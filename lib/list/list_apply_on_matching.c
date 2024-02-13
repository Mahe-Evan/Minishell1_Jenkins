/*
** EPITECH PROJECT, 2024
** list_apply_on_matching
** File description:
** Applies a function to all matching nodes
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

int list_apply_on_matching(list_t *begin, int (*f)(void *),
    void const *data_ref, int (*cmp)())
{
    list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref) == 0) {
            (*f)(tmp->data);
        }
        tmp = tmp->next;
    }
    return 0;
}
