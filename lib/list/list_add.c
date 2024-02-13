/*
** EPITECH PROJECT, 2024
** list_add
** File description:
** Adds a node to a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

void list_add(list_t **list, void *data)
{
    list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
}
