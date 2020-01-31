/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list add node
*/

#include <stdlib.h>
#include "dg_array.h"

void dg_arr_add_node_end(dg_array_t **list, dg_array_t *node)
{
    dg_array_t *tmp = *list;

    if (!node)
        return;
    node->next = 0;
    if (!(*list)) {
        node->previous = 0;
        *list = node;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        node->previous = tmp;
        tmp->next = node;
    }
}

void dg_arr_add_node_begin(dg_array_t **list, dg_array_t *node)
{
    if (!node)
        return;
    node->previous = 0;
    if (!*list) {
        node->next = 0;
        *list = node;
        return;
    }
    node->next = *list;
    (*list)->previous = node;
    *list = node;
}

void dg_arr_add_node_at(dg_array_t **list, dg_array_t *node, int index)
{
    dg_array_t *tmp = *list;
    int i = 0;

    if (!node)
        return;
    if (index <= 0 || !tmp)
        dg_arr_add_node_begin(list, node);
    else {
        for (i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (i < index)
            dg_arr_add_node_end(list, node);
        else {
            node->next = tmp;
            node->previous = tmp->previous;
            tmp->previous->next = node;
            tmp->previous = node;
        }
    }
}
