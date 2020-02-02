#include "libdragon.h"
#include "component.h"

static dg_animator_t *set_player_animator(void)
{
    dg_animator_t *animator = dg_animator_create();
    dg_spritesheet_t *ss = dg_spritesheet_create("res/time_light.png", 32, 32);
    dg_animation_t *right = dg_animation_create(ss, 5);

    dg_animation_add(right, 0);
    dg_animation_add(right, 1);
    dg_animation_add(right, 2);
    dg_animation_add(right, 3);
    dg_animation_add(right, 4);
    dg_animation_add(right, 3);
    dg_animation_add(right, 2);
    dg_animation_add(right, 1);

    dg_animator_add(animator, "right", right);

    return animator;
}

dg_entity_t *ent_warp_place(int x, int y)
{
    dg_entity_t *entity = dg_entity_create("warp_place");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, dg_cpt_animator(&set_player_animator));
    dg_entity_add_component(entity, cpt_box_trigger(0, 0, 32 * 2, 32 * 2));

    return (entity);
}
