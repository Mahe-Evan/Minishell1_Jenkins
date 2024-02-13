/*
** EPITECH PROJECT, 2024
** my_strarr_get_nindex
** File description:
** Get the index of the n occurence of a string in an array
*/

#include "my.h"
#include <stddef.h>

int my_strarr_get_nindex(char **arr, char *str, int occurence)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (my_strcmp(arr[i], str) == 0 && occurence == 0)
            return i;
        if (my_strcmp(arr[i], str) == 0 && occurence > 0)
            occurence--;
    }
    return -1;
}
