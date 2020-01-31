/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include <stdlib.h>
#include "dg_array.h"

void dg_arr_free_all(dg_array_t **list)
{
    if (*list) {
        if ((*list)->next)
            *list = (*list)->next;
        while ((*list)->next) {
            free((*list)->previous);
            *list = (*list)->next;
        }
        if ((*list)->previous)
            free((*list)->previous);
        free(*list);
    }
    *list = 0;
}

void *dg_arr_remove_end(dg_array_t **list)
{
    dg_array_t *tmp = *list;
    void *data = 0;

    if (!tmp)
        return 0;
    while (tmp->next) {
        tmp = tmp->next;
    }
    if (!tmp->previous) {
        *list = 0;
    } else {
        tmp->previous->next = 0;
        data = tmp->data;
    }
    free(tmp);
    return data;
}

void *dg_arr_remove_begin(dg_array_t **list)
{
    dg_array_t *tmp = *list;
    void *data = 0;

    *list = (*list)->next;
    if (*list)
        (*list)->previous = 0;
    data = tmp->data;
    free(tmp);
    return data;
}

static void *dg_arr_remove_middle(dg_array_t *tmp)
{
    dg_array_t *to_remove = tmp;
    void *data = 0;

    tmp = tmp->previous;
    tmp->next->next->previous = tmp;
    tmp->next = tmp->next->next;
    data = to_remove->data;
    free(to_remove);
    return data;
}

void *dg_arr_remove_at(dg_array_t **list, int id)
{
    dg_array_t *tmp = *list;
    void *data = 0;

    if (!(*list))
        return 0;
    if (id <= 0)
        data = dg_arr_remove_begin(list);
    else {
        for (int i = 0; i < id && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (!tmp->next) {
            data = dg_arr_remove_end(list);
        } else {
            data = dg_arr_remove_middle(tmp);
        }
    }
    return data;
}
