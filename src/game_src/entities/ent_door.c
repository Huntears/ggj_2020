#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_door(sfVector2f pos, dg_spritesheet_t *ss)
{
    dg_entity_t *entity = dg_entity_create("door");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, cpt_box_trigger(0, 0, 32 * 2, 64 * 2));
    dg_entity_add_component(entity, cpt_box_collider(30, 0, 10 * 2, 64 * 2));
    dg_entity_add_component(entity, cpt_spritesheet(ss));
    sfSprite *sprite = (sfSprite *) dg_entity_get_component(entity, "sprite");
    dg_spritesheet_to_sprite(ss, sprite, 0);
    return entity;
}
