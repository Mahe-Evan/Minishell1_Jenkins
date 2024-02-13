/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** 'cd' Command
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
    for (int i = 0; environ[i]; i++)
        my_printf("%s\n", environ[i]);
    return 0;
}
