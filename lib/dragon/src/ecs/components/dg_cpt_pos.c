/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component stat
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_component.h"

static void component_destroy(void *data)
{
    sfVector2f *pos = (sfVector2f *)(data);

    free(pos);
}

dg_component_t *dg_cpt_pos(int x, int y)
{
    void (*destroy)(void *) = &component_destroy;
    sfVector2f *pos = 0;
    dg_component_t *component = 0;

    pos = malloc(sizeof(sfVector2f));
    pos->x = x;
    pos->y = y;
    component = dg_component_create("pos", pos, destroy);
    return component;
}
