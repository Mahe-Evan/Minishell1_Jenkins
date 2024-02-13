/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** Copies n characters from a string into another
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int length = my_strlen(src);

    while (i < n) {
        dest[i] = src[i];
        if (i == n) {
            return NULL;
        }
        i++;
    }
    if (n > length) {
        dest[i] = '\0';
    }
    return dest;
}
