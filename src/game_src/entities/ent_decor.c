#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_decor(int x, int y, int id, dg_spritesheet_t *ss)
{
    dg_entity_t *entity = dg_entity_create("decor");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, cpt_box_collider(0, 0, 32 * 2, 32 * 2));
    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    sfSprite *sprite = (sfSprite *) dg_entity_get_component(entity, "sprite");
    dg_spritesheet_to_sprite(ss, sprite, id);
    return entity;
}
