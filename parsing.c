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

static void strip_cmd(char **cmd)
{
    while ((*cmd)[0] == ' ' || (*cmd)[0] == '\t')
        *cmd = my_slice(*cmd, 1, my_strlen(*cmd));
}

static void replace_tabs(char **cmd)
{
    for (int i = 0; (*cmd)[i]; i++) {
        if ((*cmd)[i] == '\t')
            (*cmd)[i] = ' ';
    }
}

char **get_args(void)
{
    char **args = NULL;
    char *result = NULL;
    char *line = NULL;
    size_t len = 0;

    if (isatty(STDIN_FILENO))
        my_printf("$> ");
    getline(&line, &len, stdin);
    result = my_strdup(line);
    if (result[my_strlen(result) - 1] == '\n')
        result = my_slice(line, 0, my_strlen(line) - 1);
    free(line);
    strip_cmd(&result);
    replace_tabs(&result);
    args = my_str_split(result, ' ');
    free(result);
    return args;
}

char **get_paths(char **env)
{
    char *pathlist = NULL;
    char **paths = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            pathlist = my_strdup(env[i]);
            break;
        }
    }
    if (pathlist == NULL)
        return NULL;
    pathlist = my_strconcat("./commands:",
        my_slice(pathlist, 5, my_strlen(pathlist)));
    paths = my_str_split(pathlist, ':');
    free(pathlist);
    return paths;
}

char *get_cmdpath(char *cmd, char **paths)
{
    char *cmdpath = NULL;

    if (access(cmd, F_OK) == 0 && my_strncmp(cmd, "./", 2) == 0) {
        if (access(cmd, X_OK) == 0)
            return my_strdup(cmd);
        else {
            my_printf("%s: Permission denied.\n", cmd);
            return NULL;
        }
    }
    for (int i = 0; paths[i]; i++) {
        cmdpath = my_strconcat(my_strconcat(paths[i], "/"), cmd);
        if (access(cmdpath, F_OK) == 0)
            return cmdpath;
    }
    my_printf("%s: Command not found.\n", cmd);
    return NULL;
}
