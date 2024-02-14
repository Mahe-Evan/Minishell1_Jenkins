/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Get variable environment value from key
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>

extern char **environ;

char *my_getenv(char *name)
{
    char *result = NULL;
    char *search = my_strconcat(name, "=");

    for (int i = 0; environ[i]; i++) {
        if (my_strncmp(environ[i], search, my_strlen(search)) == 0) {
            result = my_strdup(my_slice(environ[i],
                my_strlen(search), my_strlen(environ[i])));
            break;
        }
    }
    return result;
}
