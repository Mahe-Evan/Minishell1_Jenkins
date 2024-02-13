/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Debugging File
*/

#include "my.h"
#include "my_printf.h"

void display_args(char **args)
{
    my_printf("\n");
    for (int i = 0; args[i]; i++)
        my_printf("%s\n", args[i]);
    my_printf("\n");
}

void display_paths(char **paths)
{
    my_printf("\n");
    for (int i = 0; paths[i]; i++)
        my_printf("%s\n", paths[i]);
    my_printf("\n");
}
