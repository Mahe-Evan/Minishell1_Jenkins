/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Main File
*/

#include "my.h"
#include "my_printf.h"
#include "minishell1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

static int execute(char *cmdpath, char **args, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        execve(cmdpath, args, env);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
    }
    if (status == 512) {
        return 2;
    }
    if (WIFSIGNALED(status)) {
        my_printf("%s\n", strsignal(WTERMSIG(status)));
    }
    return status;
}

static int loop(char **args, char **paths, char **env, int *end)
{
    char *cmdpath = NULL;
    int status = 0;

    if (args == NULL || paths == NULL)
        return 84;
    if (my_strcmp(args[0], "exit") == 0) {
        *end = 1;
        return 0;
    }
    if (my_strcmp(args[0], "cd") == 0) {
        return change_dir(args);
    }
    cmdpath = get_cmdpath(args[0], paths);
    if (cmdpath == NULL) {
        my_printf("%s: Command not found.\n", args[0]);
    } else {
        status = execute(cmdpath, args, env);
    }
    free(cmdpath);
    return status;
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
    char **env)
{
    char **paths = NULL;
    char **args = NULL;
    int status = 0;
    int end = 0;

    while (!end) {
        args = get_args();
        paths = get_paths(env, args[0]);
        status = loop(args, paths, env, &end);
        if (status == 84)
            return 84;
        if (!isatty(STDIN_FILENO))
            end = 1;
    }
    free(paths);
    free(args);
    return status;
}
