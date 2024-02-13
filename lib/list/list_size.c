/*
** EPITECH PROJECT, 2024
** list_size
** File description:
** Returns the size of a list
*/

#include <stdlib.h>
#include "list.h"

int list_size(list_t const *begin)
{
    int counter = 0;
    list_t *tmp;

    tmp = (list_t *)begin;
    while (tmp != NULL) {
        tmp = tmp->next;
        counter++;
    }
    return counter;
}
