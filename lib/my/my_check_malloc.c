/*
** EPITECH PROJECT, 2024
** my_check_malloc
** File description:
** Checks if malloc() failed
*/

#include <stdlib.h>
#include <unistd.h>

void my_check_malloc(void *value)
{
    if (value == NULL) {
        write(2, "Error while using malloc()\n", 28);
        exit(84);
    }
}
