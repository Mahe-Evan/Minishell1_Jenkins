/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** 'unsetenv' Command
*/

#include "my.h"
#include "my_printf.h"
#include "minishell1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int check_args_count(char **args)
{
    int count = my_arrlen((void *)args);

    if (count > 2) {
        my_printf("unsetenv: Too many arguments.\n");
        return 1;
    }
    if (count < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}

static char **copy_env(char **env, char *key_to_remove)
{
    char **copy = malloc(sizeof(char *) *
        (my_arrlen((void *)env) - 1));
    int j = 0;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], key_to_remove, my_strlen(key_to_remove)) != 0) {
            copy[j] = my_strdup(env[i]);
            j++;
        }
    }
    copy[my_arrlen((void *)env) - 1] = NULL;
    return copy;
}

int my_unsetenv(char **args, char ***env)
{
    char *result = NULL;

    if (check_args_count(args) == 1)
        return 1;
    result = my_getenv(args[1], *env);
    if (result == NULL) {
        return 0;
    }
    *env = copy_env(*env, args[1]);
    return 0;
}
