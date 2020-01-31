//Auteur : Alexia
//Box collider (collision rectangulaire)

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"

//1: left, 2: right, 3:top, 4:bottom
int box_collider_test(dg_entity_t *ent1, dg_entity_t *ent2)
{
    sfFloatRect *rect1 = (sfFloatRect *)(dg_entity_get_component(ent1, "box_collider"));
    sfFloatRect *rect2 = (sfFloatRect *)(dg_entity_get_component(ent2, "box_collider"));
    sfFloatRect rect_test = {0};
    sfVector2f *pos1 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));
    sfVector2f *pos2 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));

    if (!dg_system_require(ent1, 2, "box_collider", "pos") || !dg_system_require(ent2, 2, "box_collider", "pos"))
        return 0;
    rect1->left += pos1->x;
    rect1->top += pos1->y;
    rect2->left += pos2->x;
    rect2->top += pos2->y;
    if (!sfFloatRect_intersects(rect1, rect2, &rect_test)) {
        rect1->left -= pos1->x;
        rect1->top -= pos1->y;
        rect2->left -= pos2->x;
        rect2->top -= pos2->y;
        return 0;
    }
    if (rect_test.left <= rect1->left) {
        rect1->left -= pos1->x;
        rect1->top -= pos1->y;
        rect2->left -= pos2->x;
        rect2->top -= pos2->y;
        return 1;
    }
    if (rect_test.left + rect_test.width >= rect1->left + rect1->width) {
        rect1->left -= pos1->x;
        rect1->top -= pos1->y;
        rect2->left -= pos2->x;
        rect2->top -= pos2->y;
        return 2;
    }
    if (rect_test.top <= rect1->top) {
        rect1->left -= pos1->x;
        rect1->top -= pos1->y;
        rect2->left -= pos2->x;
        rect2->top -= pos2->y;
        return 3;
    }
    rect1->left -= pos1->x;
    rect1->top -= pos1->y;
    rect2->left -= pos2->x;
    rect2->top -= pos2->y;
    return 4;
}

static void component_destroy(void *data)
{
    sfFloatRect *box_collider = (sfFloatRect *)(data);

    free(box_collider);
}

dg_component_t *cpt_box_collider(float x, float y, float width, float height)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfFloatRect *box_collider = malloc(sizeof(sfFloatRect));
    dg_component_t *component = dg_component_create("box_collider",
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
