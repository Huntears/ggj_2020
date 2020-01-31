/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : render
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"

static void display_sprite(sfVector2f camera, dg_entity_t *entity,
    dg_window_t *w)
{
    sfVector2f reverse = {-camera.x, -camera.y};
    sfSprite *sprite = 0;

    if (dg_system_require(entity, 1, "sprite")) {
            sprite = (sfSprite *)(dg_entity_get_component(entity, "sprite"));
            sfSprite_move(sprite, reverse);
            sfRenderWindow_drawSprite(w->window, sprite, NULL);
            sfSprite_move(sprite, camera);
        }
}

void dg_sys_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *camera = (sfVector2f *)(dg_entity_get_component(entity, "pos"));


    if (!entity || dg_strcmp(entity->name, "camera"))
        return;
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
            display_sprite(*camera, ent->data, w);
    }
}
