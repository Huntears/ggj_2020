#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_ladder(int x, int y, int size, dg_spritesheet_t *ss)
{
    dg_entity_t *entity = dg_entity_create("ladder");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, cpt_box_trigger(0, 0, 32 * 2, 32 * size * 2));
    dg_entity_add_component(entity, cpt_roping(size));

    sfSprite *sprite = (sfSprite *) dg_entity_get_component(entity, "sprite");
    dg_spritesheet_to_sprite(ss, sprite, 0);
    return (entity);
}
