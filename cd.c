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
#include <dirent.h>

int change_dir(char **args)
{
    DIR* directory = NULL;
    char *path = NULL;
    static char *previous = "";
    // char *previous = my_getenv("OLDPWD");

    my_printf("previous: %s\n", previous);
    if (my_arrlen((void *)args) < 2) {
        chdir(my_getenv("HOME"));
        return 0;
    }
    if (my_strcmp(args[1], "-") == 0) {
        path = previous;
        previous = my_getenv("PWD");
    } else {
        path = args[1];
    }
    if (access(path, F_OK) != 0) {
        my_printf("%s: No such file or directory\n", path);
        return 1;
    }
    directory = opendir(path);
    if (directory != NULL) {
        closedir(directory);
    } else {
        my_printf("%s: Not a directory.\n", path);
        return 1;
    }
    previous = my_getenv("PWD");
    chdir(path);
    return 0;
}
