/*
** EPITECH PROJECT, 2024
** list_apply
** File description:
** Applies a function to all nodes
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

int list_apply(list_t *begin, int (*f)(void *))
{
    list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        (*f)(tmp->data);
        tmp = tmp->next;
    }
    return 0;
}
