/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** 'cd' Command
*/

#include "my.h"
#include "my_printf.h"
#include "minishell1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int change_dir(char **args)
{
    if (my_arrlen((void *)args) < 2) {
        chdir(getenv("HOME"));
        return 0;
    }
    if (chdir(args[1]) != 0) {
        my_printf("%s: No such file or directory\n", args[1]);
        return 1;
    }
    return 0;
}
