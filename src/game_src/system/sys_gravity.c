//Auteur: Alexia
//gravity system (lol)

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"
#include "component.h"
#include "rigid_body.h"

void sys_gravity(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *pos = (sfVector2f *)(dg_entity_get_component(entity, "pos"));
    rigid_body_t *rb = (rigid_body_t *)(dg_entity_get_component(entity, "rigid_body"));
    int collisions[4] = {0};
    int tmp = 0;
    int depth = 0;
    int fdepth[4] = {0};

    (void)w;
    if (!dg_system_require(entity, 3, "pos", "box_collider", "rigid_body"))
        return;
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = box_collider_test(entity, (dg_entity_t *)(ent->data), &depth);
        if (tmp) {
            collisions[tmp - 1] = 1;
            fdepth[tmp - 1] = depth;
        }
    }
    if (collisions[0] && rb->strengh.x < 0) {
        rb->strengh.x = 0;
        pos->x += fdepth[0];
    }
    if (collisions[1] && rb->strengh.x > 0) {
        rb->strengh.x = 0;
        pos->x += fdepth[1];
    }
    if (collisions[2] && rb->strengh.y < 0) {
        rb->strengh.y = 0;
        pos->y += fdepth[2];
    }
    if (collisions[3] && rb->strengh.y > 0) {
        rb->strengh.y = 0;
        pos->y += fdepth[3];
    }
    pos->x += rb->strengh.x * dt.microseconds / 100000;
    pos->y += rb->strengh.y * dt.microseconds / 100000;
    rb->strengh.y += rb->gravity * rb->mass * dt.microseconds / 100000 * 9.81;
}
