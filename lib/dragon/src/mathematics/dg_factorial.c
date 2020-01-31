/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** mathematics calculation for the lib
*/

int dg_factorial(int n)
{
    int result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
