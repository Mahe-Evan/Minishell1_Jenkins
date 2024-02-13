/*
** EPITECH PROJECT, 2024
** Project Name
** File description:
** Project Description
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char **get_args(void)
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
    return args;
}

static char **get_paths(char **env)
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
    path = my_slice(path, 5, my_strlen(path));
    paths = my_str_split(path, ':');
    return paths;
}

static char *get_cmdpath(char *cmd, char **paths)
{
    char *cmdpath = NULL;

    for (int i = 0; paths[i]; i++) {
        cmdpath = my_strconcat(my_strconcat(paths[i], "/"), cmd);
        if (access(cmdpath, F_OK) == 0)
            return cmdpath;
    }
    return NULL;
}

static int loop(char **paths)
{
    char **args = get_args();
    char *cmdpath = NULL;

    if (args == NULL || paths == NULL)
        return 84;
    cmdpath = get_cmdpath(args[0], paths);
    if (cmdpath == NULL) {
        my_printf("%s: Command not found.\n", args[0]);
    } else {
        for (int i = 0; args[i]; i++)
            my_printf("%s\n", args[i]);
    }
    free(args);
    if (!isatty(STDIN_FILENO))
        return 1;
    return 0;
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
    char **env)
{
    char **paths = get_paths(env);
    int status = 0;

    while (status == 0) {
        status = loop(paths);
        if (status == 84)
            return 84;
    }
    for (int i = 0; paths[i]; i++)
        my_printf("%s\n", paths[i]);
    free(paths);
    return 0;
}
