/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swaps the values of two integers
*/


void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
