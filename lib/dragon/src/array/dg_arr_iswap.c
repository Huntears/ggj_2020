/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list swap
*/

#include "dg_array.h"

void dg_arr_iswap_extreme(dg_array_t **list)
{
    dg_array_t *node1 = 0;
    dg_array_t *node2 = 0;

    if (!(*list) || !(*list)->next)
        return;
    node1 = dg_arr_pop_begin(list);
    node2 = dg_arr_pop_end(list);
    dg_arr_add_node_end(list, node1);
    dg_arr_add_node_begin(list, node2);
}

void dg_arr_iswap_at(dg_array_t **list, int first, int second)
{
    dg_array_t *node1 = 0;
    dg_array_t *node2 = 0;
    int order = (first > second ? 1 : 0);

    if (!(*list) || !(*list)->next || first == second)
        return;
    node1 = dg_arr_pop_at(list, first);
    if (first < second) {
        node2 = dg_arr_pop_at(list, second - 1);
        dg_arr_add_node_at(list, node1, second - 1);
    } else {
        node2 = dg_arr_pop_at(list, second);
        dg_arr_add_node_at(list, node1, second);
    }
    dg_arr_add_node_at(list, node2, first);
}
