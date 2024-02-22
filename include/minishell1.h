/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Minishell 1 Header
*/

#pragma once

    #include "list.h"
    #include <sys/stat.h>

// Parsing
// char **get_args(void);
list_t *get_commands(int *end);
char **get_paths(char **env);
char *get_cmdpath(char *cmd, char **paths);

// Debugging
void display_args(char **args);
void display_paths(char **paths);

// Commands
int change_dir(char **args, char **env);
int my_setenv(char **args, char ***env);
int display_env(char **env);
int my_unsetenv(char **args, char ***env);

// Variable Environment Management
char *my_getenv(char *name, char **env);
