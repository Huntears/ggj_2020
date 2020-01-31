/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : animator
*/

#include <stdlib.h>
#include "libdragon.h"

void dg_sys_animator(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_animator_t *animator = (dg_animator_t *)
        (dg_entity_get_component(entity, "animator"));
    sfSprite *sprite = (sfSprite *)(dg_entity_get_component(entity, "sprite"));

    if (!dg_system_require(entity, 2, "animator", "sprite"))
        return;
    dg_animator_update_sprite(animator, sprite, dt.microseconds);
}
