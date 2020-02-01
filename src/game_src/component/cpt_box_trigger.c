//Auteur : Alexia
//Box collider (collision rectangulaire)

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"

static void absolute_collision(sfFloatRect *rect1, sfFloatRect *rect2, sfVector2f *pos1, sfVector2f *pos2)
{
    rect1->left -= pos1->x;
    rect1->top -= pos1->y;
    rect2->left -= pos2->x;
    rect2->top -= pos2->y;
}

int box_trigger_point(sfVector2f point, dg_entity_t *ent)
{
    sfFloatRect *rect = (sfFloatRect *)(dg_entity_get_component(ent, "box_trigger"));
    sfVector2f *pos = (sfVector2f *)(dg_entity_get_component(ent, "pos"));

    if (!dg_system_require(ent, 2, "box_trigger", "pos"))
        return 0;
    rect->left += pos->x;
    rect->top += pos->y;
    if (!sfFloatRect_contains(rect, point.x, point.y)) {
        rect->left -= pos->x;
        rect->top -= pos->y;
        return 0;
    }
    rect->left -= pos->x;
    rect->top -= pos->y;
    return 1;
}

int box_trigger_box(dg_entity_t *ent1, dg_entity_t *ent2)
{
    sfFloatRect *rect1 = (sfFloatRect *)(dg_entity_get_component(ent1, "box_trigger"));
    sfFloatRect *rect2 = (sfFloatRect *)(dg_entity_get_component(ent2, "box_trigger"));
    sfVector2f *pos1 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));
    sfVector2f *pos2 = (sfVector2f *)(dg_entity_get_component(ent2, "pos"));

    if (!dg_system_require(ent1, 2, "box_trigger", "pos") || !dg_system_require(ent2, 2, "box_trigger", "pos") || ent1 == ent2)
        return 0;
    rect1->left += pos1->x;
    rect1->top += pos1->y;
    rect2->left += pos2->x;
    rect2->top += pos2->y;
    if (!sfFloatRect_intersects(rect1, rect2, 0)) {
        absolute_collision(rect1, rect2, pos1, pos2);
        return 0;
    }
    absolute_collision(rect1, rect2, pos1, pos2);
    return 1;
}

static void component_destroy(void *data)
{
    sfFloatRect *box_collider = (sfFloatRect *)(data);

    free(box_collider);
}

dg_component_t *cpt_box_trigger(float x, float y, float width, float height)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfFloatRect *box_collider = malloc(sizeof(sfFloatRect));
    dg_component_t *component = dg_component_create("box_trigger",
        box_collider, destroy);

    if (!box_collider || !component) {
        dprintf(2, "Error: box_collider not created.\n");
        return 0;
    }
    box_collider->left = x;
    box_collider->top = y;
    box_collider->width = width;
    box_collider->height = height;
    return component;
}
