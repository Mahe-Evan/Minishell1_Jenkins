/*
** EPITECH PROJECT, 2024
** my_strarr_get_index
** File description:
** Get the index of the 1st occurence of a string in an array
*/

#include "my.h"
#include <stddef.h>

int my_strarr_get_index(char **arr, char *str)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (my_strcmp(arr[i], str) == 0)
            return i;
    }
    return -1;
}
