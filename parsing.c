/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Parsing File
*/

#include "my.h"
#include "my_printf.h"
#include "list.h"
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

static char **format_command(char *command)
{
    char **args = NULL;

    strip_cmd(&command);
    replace_tabs(&command);
    if (command[my_strlen(command) - 1] == '\n')
        command = my_slice(command, 0, my_strlen(command) - 1);
    args = my_str_split(command, ' ');
    return args;
}

// static void debug_commands(list_t *commands)
// {
//     list_t *command = commands;

//     while (command != NULL) {
//         my_printf("arrlen: %d\n", my_arrlen((void *)(command->data)));
//         for (int i = 0; ((char **)command->data)[i]; i++)
//             my_printf("%s\n", ((char **)command->data)[i]);
//         command = command->next;
//     }
// }
list_t *get_commands(int *end)
{
    list_t *commands = NULL;
    char *result = NULL;
    size_t len = 0;
    int getline_result = 0;

    if (isatty(STDIN_FILENO))
        my_printf("$> ");
    else {
        *end = 1;
    }
    do {
        getline_result = getline(&result, &len, stdin);
        if (getline_result == -1)
            break;
        list_add(&commands, format_command(result));
    } while (getline_result != -1 && !isatty(STDIN_FILENO));
    free(result);
    list_reverse(&commands);
    return commands;
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

    if (access(cmd, F_OK) == 0 && my_str_include(cmd, '/')) {
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
