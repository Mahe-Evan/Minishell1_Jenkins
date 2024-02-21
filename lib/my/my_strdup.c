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
    char *dest = NULL;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
