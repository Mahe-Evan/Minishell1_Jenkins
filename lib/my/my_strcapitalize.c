/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** Returns a string with the first letter of each word capitalized
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    return str;
}
