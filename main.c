/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Main File
*/

#include "my.h"
#include "my_printf.h"
#include "list.h"
#include "minishell1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

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
        if (execve(cmdpath, args, env) == -1) {
            my_printf("%s: %s\n", args[0], strerror(errno));
            return 1;
        }
    } else
        waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)) {
        my_printf("%s", strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_printf(" (core dumped)");
        my_printf("\n");
        return status;
    } else
        return WEXITSTATUS(status);
}

static int execute_shell_cmd(char *cmd, char **args, char ***env, int *end)
{
    if (my_strcmp(cmd, "exit") == 0) {
        my_printf("exit\n");
        *end = 1;
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

static int parse_command(char **args, char **paths, char ***env, int *end)
{
    char *cmdpath = NULL;
    int status = 1;
    int shell_cmd_result = 0;

    if (args == NULL || paths == NULL)
        return 84;
    shell_cmd_result = execute_shell_cmd(args[0], args, env, end);
    if (shell_cmd_result != -1)
        return shell_cmd_result;
    cmdpath = get_cmdpath(args[0], paths);
    if (cmdpath != NULL)
        status = execute(cmdpath, args, *env);
    free(cmdpath);
    return status;
}

static int loop(list_t *commands, char **paths, char ***env, int *end)
{
    list_t *command = commands;
    int status = 0;

    while (command != NULL) {
        status = parse_command(command->data, paths, env, end);
        command = command->next;
    }
    return status;
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
    char **env)
{
    char **paths = get_paths(env);
    list_t *commands = NULL;
    int status = 0;
    int end = 0;

    if (help_page(ac, av))
        return 0;
    while (!end) {
        commands = get_commands(&end);
        status = loop(commands, paths, &env, &end);
        if (status == 84)
            return 84;
        free(commands);
    }
    free(paths);
    return status;
}
