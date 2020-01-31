/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** maths functions : trigonometry
*/

#include "dg_math.h"

const double PI = 3.14159265359;
const int PRECISION = 10;

double dg_arcsin(double x)
{
    double result;
    long int top_factor = 1;
    long int sub_factor = 1;

    while (x > 1)
        x--;
    while (x < -1)
        x++;
    for (int i = 3; i <= PRECISION; i += 2) {
        top_factor *= (i - 2);
        sub_factor *= (i - 1);
        result += (top_factor / sub_factor) * (dg_fpow(x, i) / i);
    }
    return result;
}

double dg_arccos(double x)
{
    return ((PI / 2) - dg_arcsin(x));
}
