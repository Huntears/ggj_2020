/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list swap
*/

#include "dg_array.h"

void dg_arr_swap_b_to_b(dg_array_t **first, dg_array_t **second)
{
    dg_array_t *node1 = dg_arr_pop_begin(first);
    dg_array_t *node2 = dg_arr_pop_begin(second);

    dg_arr_add_node_begin(second, node1);
    dg_arr_add_node_begin(first, node2);
}

void dg_arr_swap_b_to_e(dg_array_t **first, dg_array_t **second)
{
    dg_array_t *node1 = dg_arr_pop_begin(first);
    dg_array_t *node2 = dg_arr_pop_end(second);

    dg_arr_add_node_end(second, node1);
    dg_arr_add_node_begin(first, node2);
}

void dg_arr_swap_e_to_b(dg_array_t **first, dg_array_t **second)
{
    dg_array_t *node1 = dg_arr_pop_end(first);
    dg_array_t *node2 = dg_arr_pop_begin(second);

    dg_arr_add_node_begin(second, node1);
    dg_arr_add_node_end(first, node2);
}

void dg_arr_swap_e_to_e(dg_array_t **first, dg_array_t **second)
{
    dg_array_t *node1 = dg_arr_pop_end(first);
    dg_array_t *node2 = dg_arr_pop_end(second);

    dg_arr_add_node_end(second, node1);
    dg_arr_add_node_end(first, node2);
}

void dg_arr_swap_at(dg_array_t **first, int fi, dg_array_t **second, int si)
{
    dg_array_t *node1 = dg_arr_pop_at(first, fi);
    dg_array_t *node2 = dg_arr_pop_at(second, si);

    dg_arr_add_node_at(second, node1, si);
    dg_arr_add_node_at(first, node2, fi);
}
