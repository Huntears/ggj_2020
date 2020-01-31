/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** maths functions : trigonometry
*/

#include "dg_math.h"

const double PI = 3.14159265359;
const int PRECISION = 10;

double dg_get_radian(double angle)
{
	while (angle > PI)
		angle -= 2 * PI;
	while (angle < -PI)
		angle += 2 * PI;
	return angle;
}

double dg_cos(double x)
{
    double result = 1;
    long int factorial = 1;
    int value = 1;

    x = dg_get_radian(x);
    for (int i = 2; i <= PRECISION; i += 2) {
        factorial *= (i - 1) * i;
        value *= -1;
        result += value * ((double)(1)/factorial) * dg_fpow(x, i);
    }
    return result;
}

double dg_sin(double x)
{
    double result;
    long int factorial = 1;
    int value = 1;

    x = dg_get_radian(x);
    result = x;
    for (int i = 3; i <= PRECISION; i += 2) {
        factorial *= (i - 1) * i;
        value *= -1;
        result += value * ((double)(1)/factorial) * dg_fpow(x, i);
    }
    return result;
}

double dg_tan(double x)
{
    return (dg_sin(x) / dg_cos(x));
}
