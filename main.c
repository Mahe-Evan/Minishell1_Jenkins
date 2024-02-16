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

static int help_page(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("USAGE\n");
        my_printf("    ./mysh\n");
        my_printf("DESCRIPTION\n");
        my_printf("    Simple shell project.\n");
        return 1;
    }
    return 0;
}

static int execute(char *cmdpath, char **args, char **env)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        if (execve(cmdpath, args, env) == -1)
            return 84;
    } else {
        waitpid(pid, &status, 0);
    }
    if (WIFSIGNALED(status)) {
        my_printf("%s (core dumped)\n", strsignal(WTERMSIG(status)));
        return status;
    } else {
        return WEXITSTATUS(status);
    }
}

static int execute_shell_cmd(char *cmd, char **args, char ***env)
{
    if (my_strcmp(cmd, "exit") == 0) {
        my_printf("exit\n");
        return 0;
    }
    if (my_strcmp(cmd, "cd") == 0)
        return change_dir(args, *env);
    if (my_strcmp(cmd, "setenv") == 0)
        return my_setenv(args, env);
    if (my_strcmp(cmd, "env") == 0)
        return display_env(*env);
    if (my_strcmp(cmd, "unsetenv") == 0)
        return my_unsetenv(args, env);
    if (my_strlen(cmd) == 0)
        return 0;
    return -1;
}

static int loop(char **args, char **paths, char ***env)
{
    char *cmdpath = NULL;
    int status = 1;
    int shell_cmd_result = 0;

    if (args == NULL || paths == NULL)
        return 84;
    shell_cmd_result = execute_shell_cmd(args[0], args, env);
    if (shell_cmd_result != -1)
        return shell_cmd_result;
    cmdpath = get_cmdpath(args[0], paths);
    if (cmdpath != NULL) {
        status = execute(cmdpath, args, *env);
    }
    free(cmdpath);
    return status;
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
    char **env)
{
    char **paths = get_paths(env);
    char **args = NULL;
    int status = 0;
    int end = 0;

    if (help_page(ac, av))
        return 0;
    while (!end) {
        args = get_args();
        status = loop(args, paths, &env);
        if (status == 84)
            return 84;
        if (!isatty(STDIN_FILENO) || my_strcmp(args[0], "exit") == 0)
            end = 1;
        free(args);
    }
    free(paths);
    return status;
}
