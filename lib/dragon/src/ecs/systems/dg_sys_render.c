/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : render
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"

static int is_in_screen(sfSprite *sprite, sfVector2f camera, dg_window_t *w)
{
    sfFloatRect rect = {0};
    sfVector2u window = {0};
    int stat = 1;

    if (!sprite || !w)
        return 0;
    rect = sfSprite_getGlobalBounds(sprite);
    window = sfRenderWindow_getSize(w->window);
    stat = (rect.left + rect.width - camera.x < 0) ? 0 : stat;
    stat = (rect.top + rect.height - camera.y < 0) ? 0 : stat;
    stat = (rect.left - camera.x > window.x) ? 0 : stat;
    stat = (rect.top - camera.y > window.y) ? 0 : stat;
    return stat;
}

static void display_sprite(sfVector2f camera, dg_entity_t *entity,
    dg_window_t *w)
{
    sfVector2f reverse = {-camera.x, -camera.y};
    sfSprite *sprite = 0;

    if (dg_system_require(entity, 1, "sprite")) {
            sprite = (sfSprite *)(dg_entity_get_component(entity, "sprite"));
            if (is_in_screen(sprite, camera, w)) {
                sfSprite_move(sprite, reverse);
                sfRenderWindow_drawSprite(w->window, sprite, NULL);
                sfSprite_move(sprite, camera);
            }
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
