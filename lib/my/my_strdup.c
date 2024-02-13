/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Duplicates a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(my_strlen(src));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
