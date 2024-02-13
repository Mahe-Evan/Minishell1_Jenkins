/*
** EPITECH PROJECT, 2024
** list_get
** File description:
** Gets the n node of a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

list_t *list_get(list_t const *begin, int n)
{
    list_t *tmp;
    list_t *result = NULL;

    tmp = (list_t *)begin;
    while (tmp != NULL && n != 0) {
        if (n == 0) {
            result = tmp;
            break;
        }
        tmp = tmp->next;
        n--;
    }
    return result;
}
