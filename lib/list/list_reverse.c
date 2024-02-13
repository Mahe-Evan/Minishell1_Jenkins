/*
** EPITECH PROJECT, 2024
** list_reverse
** File description:
** Reverses a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

void list_reverse(list_t **begin)
{
    list_t *result = NULL;
    list_t *tmp;

    tmp = *begin;
    while (tmp != NULL) {
        list_add(&result, tmp->data);
        tmp = tmp->next;
    }
    *begin = result;
}
