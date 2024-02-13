/*
** EPITECH PROJECT, 2024
** my_str_split
** File description:
** Split a string into an array of strings
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

char **list_to_array(list_t *list)
{
    char **arr = malloc(sizeof(char *) * (list_size(list) + 1));
    int i = 0;

    list_reverse(&list);
    while (list != NULL) {
        arr[i] = list->data;
        list = list->next;
        i++;
    }
    arr[i] = NULL;
    return arr;
}

static void goto_next_word(char *str, int *i, char separator,
    int *current_word_start)
{
    while (str[*i] == separator) {
        *i += 1;
        *current_word_start = *i;
    }
}

char **my_str_split(char *str, char separator)
{
    list_t *list = NULL;
    int i = 0;
    int current_word_start = 0;

    str = my_strip(str, separator);
    while (str[i] != '\0') {
        if (str[i] == separator) {
            list_add(&list, my_slice(str, current_word_start, i));
            goto_next_word(str, &i, separator, &current_word_start);
        } else {
            i++;
        }
    }
    list_add(&list, my_slice(str, current_word_start, i));
    free(str);
    return list_to_array(list);
}
