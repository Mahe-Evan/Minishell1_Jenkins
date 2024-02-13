/*
** EPITECH PROJECT, 2024
** my_puterr
** File description:
** Prints a string on the error output
*/

#include "my.h"
#include <unistd.h>

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}
