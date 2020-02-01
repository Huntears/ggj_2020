#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libdragon.h"
#include "rigid_body.h"
#include "component.h"
#include "inventory.h"
#include "entity.h"

static dg_entity_t *touch_an_object(dg_entity_t *entity, dg_array_t **entities)
{
    int tmp = 0;

    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        if (dg_entity_has_component((dg_entity_t *)(ent->data), "catchable") >= 0) {
                tmp = box_trigger_box(entity, (dg_entity_t *)(ent->data));
            if (tmp)
                return (dg_entity_t *)(ent->data);
        }
    }
    return 0;
}

void system_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    rigid_body_t *rb = (rigid_body_t *)(dg_entity_get_component(entity, "rigid_body"));
    dg_animator_t *animator = (dg_animator_t *)(dg_entity_get_component(entity, "animator"));
    inventory_t *inv = (inventory_t *)(dg_entity_get_component(entity, "inventory"));
    dg_entity_t *touched = 0;
    int collisions[4] = {0};
    int tmp = 0;

    (void)w;
    (void)entities;
    (void)dt;
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = box_collider_test(entity, (dg_entity_t *)(ent->data), NULL);
        if (tmp)
            collisions[tmp - 1] = 1;
    }
    if (!dg_system_require(entity, 4, "animator", "rigid_body", "box_collider", "box_trigger") || strcmp(entity->name, "player"))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD)) {
        rb->strengh.x = 40;
        dg_animator_set_animation(animator, "right");
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyA)) {
        rb->strengh.x = -40;
        dg_animator_set_animation(animator, "left");
    } else {
        rb->strengh.x = 0;
        dg_animator_set_animation(animator, "up");
    }
    if ((sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyW)|| sfKeyboard_isKeyPressed(sfKeySpace)) && collisions[3]) {
        rb->strengh.y = -100;
    }
    touched = touch_an_object(entity, entities);
    if (sfMouse_isButtonPressed(sfMouseLeft) && touched) {
        grab(inv, touched, entities, 0);
    }
}
