#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libdragon.h"

void sys_camera_follow_player(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    dg_entity_t *player = dg_get_entity(*entities, "player");

    (void)w;
    (void)dt;
    if (strcmp(entity->name, "camera") && player)
        return;
    sfVector2f *pos_camera = (sfVector2f *) (dg_entity_get_component(entity, "pos"));
    sfVector2f *pos_player = (sfVector2f *) (dg_entity_get_component(player, "pos"));
    *pos_camera = (sfVector2f) {pos_player->x - 560, pos_player->y - 280};
}
