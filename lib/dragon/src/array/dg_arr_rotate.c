/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list rotation
*/

#include "dg_array.h"

void dg_arr_itransfer_b_to_e(dg_array_t **list)
{
    dg_array_t *node = dg_arr_pop_begin(list);

    dg_arr_add_node_end(list, node);
}

void dg_arr_itransfer_e_to_b(dg_array_t **list)
{
    dg_array_t *node = dg_arr_pop_end(list);

    dg_arr_add_node_begin(list, node);
}

void dg_arr_itransfer_at(dg_array_t **list, int src, int target)
{
    dg_array_t *node = 0;

    if (src == target)
        return;
    node = dg_arr_pop_at(list, src);
    dg_arr_add_node_at(list, node, target);
}
