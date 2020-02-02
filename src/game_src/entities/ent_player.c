#include "libdragon.h"
#include "component.h"

static dg_animator_t *set_player_animator(void)
{
    dg_animator_t *animator = dg_animator_create();
    dg_spritesheet_t *ss = dg_spritesheet_create("res/player.png", 32, 64);
    dg_animation_t *right = dg_animation_create(ss, 10);
    dg_animation_t *up = dg_animation_create(ss, 10);
    dg_animation_t *left = dg_animation_create(ss, 10);

    dg_animation_add(right, 7);
    dg_animation_add(right, 6);
    dg_animation_add(right, 5);
    dg_animation_add(right, 6);

    dg_animation_add(left, 1);
    dg_animation_add(left, 2);
    dg_animation_add(left, 3);
    dg_animation_add(left, 2);

    dg_animation_add(up, 0);

    dg_animator_add(animator, "right", right);
    dg_animator_add(animator, "up", up);
    dg_animator_add(animator, "left", left);

    return animator;
}

dg_entity_t *ent_player(int x, int y)
{
    dg_entity_t *entity = dg_entity_create("player");
    sfVector2f scale = {2, 2};

    dg_entity_add_component(entity, cpt_box_collider(0, 14 * 2, 32 * 2, 50 * 2));
    dg_entity_add_component(entity, cpt_box_trigger(0, 14 * 2, 32 * 2, 50 * 2));
    dg_entity_add_component(entity, cpt_rigid_body(1, 1));
    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, dg_cpt_animator(&set_player_animator));
    dg_entity_add_component(entity, cpt_inventory());
    return entity;
}
