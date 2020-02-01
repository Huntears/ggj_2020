#include "libdragon.h"
#include "component.h"

static dg_animator_t *set_furret_animator(void)
{
    dg_animator_t *animator = dg_animator_create();
    dg_spritesheet_t *ss = dg_spritesheet_create("res/furret.png", 444, 250);
    dg_animation_t *anim = dg_animation_create(ss, 10);

    for (int i = 0; i < 57; i++) {
        dg_animation_add(anim, i);
    }

    dg_animator_add(animator, "right", anim);
    return animator;
}

dg_entity_t *ent_furret(int x, int y)
{
    dg_entity_t *entity = dg_entity_create("furret");
    sfVector2f scale = {0.5, 0.5};

    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    dg_entity_add_component(entity, dg_cpt_sprite(&scale));
    dg_entity_add_component(entity, dg_cpt_animator(&set_furret_animator));
    dg_entity_add_component(entity, cpt_music("res/furret.ogg"));
    return entity;
}
