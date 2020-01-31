/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include "dg_array.h"

void dg_arr_transfer_b_to_b(dg_array_t **src, dg_array_t **target)
{
    dg_array_t *node = dg_arr_pop_begin(src);

    dg_arr_add_node_begin(target, node);
}

void dg_arr_transfer_b_to_e(dg_array_t **src, dg_array_t **target)
{
    dg_array_t *node = dg_arr_pop_begin(src);

    dg_arr_add_node_end(target, node);
}

void dg_arr_transfer_e_to_b(dg_array_t **src, dg_array_t **target)
{
    dg_array_t *node = dg_arr_pop_end(src);

    dg_arr_add_node_begin(target, node);
}

void dg_arr_transfer_e_to_e(dg_array_t **src, dg_array_t **target)
{
    dg_array_t *node = dg_arr_pop_end(src);

    dg_arr_add_node_end(target, node);
}

void dg_arr_transfer_at(dg_array_t **src, int si, dg_array_t **tar, int ti)
{
    dg_array_t *node = dg_arr_pop_at(src, si);

    dg_arr_add_node_at(tar, node, ti);
}
