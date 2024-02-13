/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i = 0;

    if (my_strlen(src) == 0) {
        return dest;
    }
    while (src[i] != '\0') {
        dest[i + dest_length] = src[i];
        i++;
    }
    return dest;
}
