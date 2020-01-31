/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_dg_arr
*/

#include <stdlib.h>
#include "dg_array.h"

void dg_arr_add_end(dg_array_t **list, void *data)
{
    dg_array_t *new = malloc(sizeof(dg_array_t));
    dg_array_t *old_last = 0;

    new->data = data;
    new->next = 0;
    if (!(*list)) {
        new->previous = 0;
        *list = new;
    } else {
        old_last = *list;
        while (old_last->next)
            old_last = old_last->next;
        old_last->next = new;
        new->previous = old_last;
    }
}

void dg_arr_add_begin(dg_array_t **list, void *data)
{
    dg_array_t *new = malloc(sizeof(dg_array_t));

    new->data = data;
    new->previous = 0;
    if (!*list) {
        new->next = 0;
        *list = new;
        return;
    }
    new->next = *list;
    (*list)->previous = new;
    *list = new;
}

void dg_arr_add_at(dg_array_t **list, void *data, int index)
{
    dg_array_t *tmp = *list;
    dg_array_t *new = malloc(sizeof(dg_array_t));
    int i = 0;

    if (index <= 0 || !tmp)
        dg_arr_add_begin(list, data);
    else {
        new->data = data;
        for (i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (i < index)
            dg_arr_add_end(list, data);
        else {
            new->next = tmp;
            new->previous = tmp->previous;
            tmp->previous->next = new;
            tmp->previous = new;
        }
    }
}

void *dg_arr_get_data(dg_array_t *list, int index)
{
    dg_array_t *tmp = list;
    void *data = 0;

    if (tmp) {
        for (int i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        data = tmp->data;
    }
    return data;
}

dg_array_t *dg_arr_get(dg_array_t *list, int index)
{
    dg_array_t *tmp = list;

    if (index < 0)
        return 0;
    for (int i = 0; i < index && tmp->next && tmp; i++) {
        tmp = tmp->next;
    }
    return tmp;
}
