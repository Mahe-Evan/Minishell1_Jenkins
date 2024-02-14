/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Get variable environment value from key
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>

char *my_getenv(char *name, char **env)
{
    char *result = NULL;
    char *search = my_strconcat(name, "=");

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], search, my_strlen(search)) == 0) {
            result = my_strdup(my_slice(env[i],
                my_strlen(search), my_strlen(env[i])));
            break;
        }
    }
    return result;
}
