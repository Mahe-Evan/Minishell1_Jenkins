/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** Minishell 1 Header
*/

#pragma once

    #include <sys/stat.h>

// Parsing
char **get_args(void);
char **get_paths(char **env, char *cmd);
char *get_cmdpath(char *cmd, char **paths);

// Debugging
void display_args(char **args);
void display_paths(char **paths);

// Commands
int change_dir(char **args);
