/*
** EPITECH PROJECT, 2024
** list_destroy
** File description:
** Destroys a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"
#include <stdlib.h>

void list_destroy(list_t *begin)
{
    if (begin == NULL)
        return;
    list_destroy(((begin)->next));
    free(begin);
}
