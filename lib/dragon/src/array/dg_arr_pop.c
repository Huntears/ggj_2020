/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include <stdlib.h>
#include "dg_array.h"

dg_array_t *dg_arr_pop_end(dg_array_t **list)
{
    dg_array_t *poped = *list;

    if (!(*list))
        return 0;
    while (poped->next) {
        poped = poped->next;
    }
    if (!poped->previous) {
        *list = 0;
    } else {
        poped->previous->next = 0;
    }
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

dg_array_t *dg_arr_pop_begin(dg_array_t **list)
{
    dg_array_t *poped = *list;

    if (!*list)
        return 0;
    if (!(*list)->next) {
        *list = 0;
    } else {
        *list = (*list)->next;
        (*list)->previous = 0;
    }
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

static dg_array_t *dg_arr_pop_middle(dg_array_t *tmp)
{
    dg_array_t *poped = tmp;

    tmp = tmp->previous;
    tmp->next->next->previous = tmp;
    tmp->next = tmp->next->next;
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

dg_array_t *dg_arr_pop_at(dg_array_t **list, int id)
{
    dg_array_t *poped = *list;

    if (!*list)
        return 0;
    if (id <= 0)
        poped = dg_arr_pop_begin(list);
    else {
        for (int i = 0; i < id && poped->next; i++) {
            poped = poped->next;
        }
        if (!poped->next) {
            poped = dg_arr_pop_end(list);
        } else {
            poped = dg_arr_pop_middle(poped);
        }
    }
    return poped;
}
