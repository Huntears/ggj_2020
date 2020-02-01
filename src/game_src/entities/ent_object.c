#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_object(char *key, dg_spritesheet_t *ss, sfVector2f pos, sfVector2f size)
{
    dg_entity_t *entity = dg_entity_create(key);
    sfVector2f scale = {3, 3};

    (void)size;
    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, cpt_catchable());
    sfSprite *sprite = (sfSprite *) dg_entity_get_component(entity, "sprite");
    dg_spritesheet_to_sprite(ss, sprite, 0);
    return entity;
}
