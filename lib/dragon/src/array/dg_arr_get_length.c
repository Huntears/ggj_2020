/*
** EPITECH PROJECT, 2019
** liblist
** File description:
** linked_list get length
*/

#include <stdlib.h>
#include "dg_array.h"

int dg_arr_get_size(dg_array_t *list)
{
    dg_array_t *tmp = list;
    int size = 0;

    if (!list)
        return 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}
