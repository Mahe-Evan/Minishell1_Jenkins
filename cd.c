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

static void change_previous_dir(char **args, char **path, char **previous)
{
    char *tmp = NULL;

    if (my_strcmp(args[1], "-") == 0) {
        tmp = *path;
        *path = *previous;
        *previous = tmp;
    } else {
        *path = args[1];
    }
}

static int check_directory(DIR *directory, char *path)
{
    if (directory != NULL) {
        closedir(directory);
    } else if (access(path, R_OK)){
        my_printf("%s: Permission denied.\n", path);
        return 1;
    } else {
        my_printf("%s: Not a directory.\n", path);
        return 1;
    }
    return 0;
}

static int check_exists(char *path)
{
    if (access(path, F_OK) != 0) {
        my_printf("%s: No such file or directory.\n", path);
        return 1;
    }
    return 0;
}

int change_dir(char **args, char **env)
{
    DIR* directory = NULL;
    char *path = NULL;
    static char *previous = NULL;

    if (previous == NULL)
        previous = getcwd(NULL, 0);
    if (my_arrlen((void *)args) < 2 || my_strncmp(args[1], "~", 1) == 0) {
        chdir(my_getenv("HOME", env));
        return 0;
    }
    change_previous_dir(args, &path, &previous);
    if (check_exists(path) == 1)
        return 1;
    directory = opendir(path);
    if (check_directory(directory, path) == 1)
        return 1;
    previous = getcwd(NULL, 0);
    chdir(path);
    return 0;
}
