/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** mathematics calculation for the lib
*/

int dg_pow(int number, int pow)
{
    int result = number;

    if (pow == 0)
        return 1;
    if (pow > 0)
        for (int i = 1; i < pow; i++)
            result *= number;
    else
        result = number / dg_pow(number, 1 - pow);
    return result;
}

double dg_fpow(double number, int pow)
{
    double result = number;

    if (pow == 0)
        return 1;
    if (pow > 0)
        for (int i = 1; i < pow; i++)
            result *= number;
    else
        result = number / dg_pow(number, 1 - pow);
    return result;
}
