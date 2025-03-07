# Minishell1

Minishell1 is a minimalist UNIX command interpreter written in C. This project, inspired by TCSH, is designed as a foundational step toward more advanced shells. It provides basic command execution and supports a set of built-in commands.

## Project Goals

- **Interactive Shell:** Display a prompt (e.g., `$>`) and wait for user input.
- **Command Execution:** Run commands available in the system PATH or specified with a direct path.
- **Built-in Commands:** Implement essential functions such as `cd`, `setenv`, `unsetenv`, `env`, and `exit`.
- **Error Handling:** Show error messages on stderr and return exit code 84 when an error occurs.
- **Environment Management:** Properly handle and maintain the initial environment.

## Features

- **Prompt & Input:** The shell displays a prompt and processes user commands.
- **Basic Execution:** Supports simple command execution without advanced features like pipes or redirections.
- **Exit Status:** The shell returns the same exit status as the command executed.
- **Built-ins:** Implements core built-in commands to manage directories and environment variables.

## Prerequisites

- C compiler (gcc, clang, etc.)
- Make utility

## Compilation

To compile the project, run:

```bash
make
```

This command builds the executable `mysh`.

## Usage

Launch the shell interactively:

```bash
./mysh
```

You can also pipe commands directly into the shell:

```bash
echo "command" | ./mysh
```

### Examples

Interactive session:

```bash
./mysh
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test
```

If a command is not found, the shell will display an error message and re-prompt for input.
