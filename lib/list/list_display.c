/*
** EPITECH PROJECT, 2024
** list_display
** File description:
** Displays a list
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

void list_display(list_t *list)
{
    list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}
