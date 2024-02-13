/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** Checks if the number is negative
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
    return 0;
}
