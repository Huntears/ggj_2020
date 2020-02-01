#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libdragon.h"
#include "rigid_body.h"
#include "component.h"

void system_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    rigid_body_t *rb = (rigid_body_t *)(dg_entity_get_component(entity, "rigid_body"));
    dg_animator_t *animator = (dg_animator_t *)(dg_entity_get_component(entity, "animator"));
    int collisions[4] = {0};
    int tmp = 0;

    (void)w;
    (void)entities;
    (void)dt;
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = box_collider_test(entity, (dg_entity_t *)(ent->data));
        if (tmp)
            collisions[tmp - 1] = 1;
    }
    if (!dg_system_require(entity, 3, "animator", "sprite", "pos") || strcmp(entity->name, "player"))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        rb->strengh.x = 20;
        dg_animator_set_animation(animator, "right");
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        rb->strengh.x = -20;
        dg_animator_set_animation(animator, "left");
    } else {
        rb->strengh.x = 0;
        dg_animator_set_animation(animator, "up");
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && collisions[3]) {
        rb->strengh.y = -50;
    }
}
