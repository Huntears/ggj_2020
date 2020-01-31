/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component sprite
*/

#include "dg_component.h"
#include "libdragon.h"

static void component_destroy(void *data)
{
    sfSprite *sprite = (sfSprite *)(data);

    sfSprite_destroy(sprite);
}

dg_component_t *dg_cpt_sprite(sfVector2f *scale)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfSprite *sprite = sfSprite_create();
    dg_component_t *component = dg_component_create("sprite", sprite, destroy);

    if (scale)
        sfSprite_setScale(sprite, *scale);
    return component;
}
