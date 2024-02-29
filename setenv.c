/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** 'setenv' Command
*/

#include "my.h"
#include "my_printf.h"
#include "minishell1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char **copy_env(char **env, int new)
{
    char **copy = malloc(sizeof(char *) *
        (my_arrlen((void *)env) + new + 1));

    for (int i = 0; env[i]; i++) {
        copy[i] = my_strdup(env[i]);
    }
    copy[my_arrlen((void *)env) + new] = NULL;
    if (new)
        copy[my_arrlen((void *)env)] = NULL;
    return copy;
}

static void edit_env(char **env, char *key, char *value)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], key, my_strlen(key)) == 0) {
            env[i] = my_strconcat(key, my_strconcat("=", value));
            break;
        }
    }
}

static void add_or_edit_env(char ***env __attribute__((unused)), char *key,
    char *value)
{
    char **newenv = NULL;
    int exists = my_getenv(key, *env) != NULL;

    newenv = copy_env(*env, !exists);
    if (exists) {
        edit_env(newenv, key, value);
    } else {
        newenv[my_arrlen((void *)*env)] = my_strconcat(key,
            my_strconcat("=", value));
    }
    *env = newenv;
}

static int check_args_amount(int ac)
{
    if (ac > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 84;
    }
    return 0;
}

static int check_variable_name(char *name)
{
    for (int i = 0; name[i]; i++) {
        if (i == 0 && name[i] >= '0' && name[i] <= '9') {
            my_printf("setenv: Variable name must begin with a letter.\n");
            return 84;
        }
        if (!(name[i] >= 97 && name[i] <= 122) &&
            name[i] != '_' && !(name[i] >= 65 && name[i] <= 90) &&
            !(name[i] >= 48 && name[i] <= 57)) {
                my_printf("setenv: Variable name must contain");
                my_printf(" alphanumeric characters.\n");
                return 84;
        }
    }
    return 0;
}

int my_setenv(char **args, char ***env)
{
    int ac = my_arrlen((void *)args);

    if (check_args_amount(ac) == 84 ||
        (ac >= 2 && check_variable_name(args[1]) == 84))
            return 1;
    if (ac == 1) {
        display_env(*env);
        return 0;
    }
    if (ac == 2) {
        add_or_edit_env(env, args[1], "");
        return 0;
    }
    add_or_edit_env(env, args[1], args[2]);
    return 0;
}
