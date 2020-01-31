/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list merge two lists
*/

#include "dg_array.h"

void dg_arr_merge(dg_array_t **target, dg_array_t **to_merge)
{
    dg_array_t *tmp = *target;

    if (!(*to_merge))
        return;
    if (!(*target)) {
        *target = *to_merge;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *to_merge;
    (*to_merge)->previous = tmp;
}

static void dg_arr_merge_between(
    dg_array_t **target,
    dg_array_t **to_merge,
    dg_array_t *first_node,
    dg_array_t *second_node)
{
    dg_array_t *tmp = *to_merge;

    while (tmp->next)
        tmp = tmp->next;
    if (first_node)
        first_node->next = *to_merge;
    else
        *target = *to_merge;
    (*to_merge)->previous = first_node;
    tmp->next = second_node;
    second_node->previous = tmp;
}

void dg_arr_merge_at(dg_array_t **target, dg_array_t **to_merge, int index)
{
    dg_array_t *first_node = 0;
    dg_array_t *second_node = *target;
    int i = 0;

    if (!(*target)) {
        *target = *to_merge;
    } else if (*to_merge) {
        for (i = 0; i < index && second_node->next; i++)
            second_node = second_node->next;
        first_node = second_node->previous;
        if (i < index)
            dg_arr_merge(target, to_merge);
        else
            dg_arr_merge_between(target, to_merge, first_node, second_node);
    }
}
