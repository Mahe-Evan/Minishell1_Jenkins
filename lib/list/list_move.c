/*
** EPITECH PROJECT, 2024
** list_move
** File description:
** Moves a node from a list to another
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

void list_move(list_t **src, list_t **dest,
    void *data_ref, int (*cmp)())
{
    if (list_include(*src, data_ref, cmp)) {
        list_remove(src, data_ref, cmp);
        list_add(dest, data_ref);
    }
}
