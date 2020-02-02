#include <stdlib.h>
#include "libdragon.h"

void sys_set_pos_sprite(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfSprite *sprite = (sfSprite *)(dg_entity_get_component(entity, "sprite"));

    (void)w;
    (void)entities;
    (void)dt;
    if (!dg_system_require(entity, 2, "pos", "sprite"))
        return;
    sfSprite_setPosition(sprite, *pos);
}