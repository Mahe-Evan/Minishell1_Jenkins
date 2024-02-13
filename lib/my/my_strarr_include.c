/*
** EPITECH PROJECT, 2024
** my_strarr_include
** File description:
** Returns if an array includes a string
*/

#include "my.h"
#include <stddef.h>

int my_strarr_include(char **arr, char *str)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (my_strcmp(arr[i], str) == 0)
            return 1;
    }
    return 0;
}
