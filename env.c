/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** 'env' Command
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int display_env(char **env)
{
    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
    return 0;
}
