/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Concatenates two strings until n bytes
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_length = my_strlen(dest);
    int i = 0;

    if (my_strlen(src) == 0) {
        return dest;
    }
    while (src[i] != '\0' && i < nb) {
        dest[i + dest_length] = src[i];
        i++;
    }
    return dest;
}
