/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Reverses a string
*/

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}
