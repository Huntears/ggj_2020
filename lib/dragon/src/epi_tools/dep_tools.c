/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech tools
*/

#include <stdlib.h>

int dg_strcmp(char const *s1, char const *s2)
{
    int c;

    if (!s1 || !s2)
        return -1;
    for (c = 0; s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0'; c++);
    return s1[c] - s2[c];
}
