/*
** EPITECH PROJECT, 2024
** list_include
** File description:
** Returns if the data is in the list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

int list_include(list_t const *begin,
    void const *data_ref, int (*cmp)())
{
    list_t *tmp = (list_t *)begin;

    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref)) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
