/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** Calculates the power of a number
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    return my_compute_power_rec(nb, p - 1) * nb;
}
