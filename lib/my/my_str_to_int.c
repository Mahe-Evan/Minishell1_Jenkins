/*
** EPITECH PROJECT, 2024
** my_str_to_int
** File description:
** Converts a string to an int
*/

#include "my.h"

static int power_10(int x)
{
    int result = 1;

    for (int i = 0; i < x; i++) {
        result *= 10;
    }
    return result;
}

int my_str_to_int(char *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (str[i] > '9' || str[i] < '0')
            return -1;
        result += (str[i] - '0') * power_10(my_strlen(str) - i - 1);
        i++;
    }
    return result;
}
