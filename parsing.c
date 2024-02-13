/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Parsing File
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **get_args(void)
{
    char **args = NULL;
    char *result = NULL;
    char *line = NULL;
    size_t len = 0;

    if (isatty(STDIN_FILENO))
        my_printf("$> ");
    getline(&line, &len, stdin);
    result = my_slice(line, 0, my_strlen(line) - 1);
    free(line);
    args = my_str_split(result, ' ');
    free(result);
    return args;
}

char **get_paths(char **env, char *cmd)
{
    char *path = NULL;
    char **paths = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path = my_strdup(env[i]);
            break;
        }
    }
    if (path == NULL)
        return NULL;
    path = my_strconcat(my_slice(path, 5, my_strlen(path)), ":./commands");
    if (my_strncmp(cmd, "./", 2) == 0)
        path = my_strconcat(path, ":./");
    paths = my_str_split(path, ':');
    free(path);
    return paths;
}

char *get_cmdpath(char *cmd, char **paths)
{
    char *cmdpath = NULL;

    for (int i = 0; paths[i]; i++) {
        cmdpath = my_strconcat(my_strconcat(paths[i], "/"), cmd);
        if (access(cmdpath, F_OK) == 0)
            return cmdpath;
    }
    return NULL;
}
