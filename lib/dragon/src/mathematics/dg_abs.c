/*
** EPITECH PROJECT, 2020
** libdragon
** File description:
** return absolute of a number
*/

int dg_abs(int number)
{
    if (number < 0)
        number *= -1;
    return number;
}
