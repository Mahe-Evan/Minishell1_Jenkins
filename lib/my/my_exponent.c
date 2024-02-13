/*
** EPITECH PROJECT, 2024
** my_exponent
** File description:
** Calculates the exponent of a number
*/

int my_exponent(int x, int y)
{
    int result = 1;

    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}
