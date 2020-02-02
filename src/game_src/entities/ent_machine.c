#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_machine(sfVector2f pos)
{
    dg_entity_t *entity = dg_entity_create("machine");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, cpt_box_trigger(0, 0, 64 * 2, 64 * 2));
    sfSprite *sprite = (sfSprite *) dg_entity_get_component(entity, "sprite");
    dg_spritesheet_to_sprite(dg_spritesheet_create("res/machine.png", 64, 64), sprite, 0);
    return entity;
}
