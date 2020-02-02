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

static float calc_surface(sfFloatRect rect, sfFloatRect sur, int side)
{
    float tr = 0;

    if (side == 1 && sur.left == rect.left) {
        tr = sur.height;
    }
    else if (side == 2 && sur.left + sur.width == rect.left + rect.width) {
        tr = sur.height;
    }
    if (side == 3 && sur.top == rect.top) {
        tr = sur.width;
    }
    if (side == 4 && sur.top + sur.height == rect.top + rect.height) {
        tr = sur.width;
    }
    return tr;
}

static int biggest_surface(sfFloatRect rect, sfFloatRect sur)
{
    float collision[4] = {calc_surface(rect, sur, 1), calc_surface(rect, sur, 2), calc_surface(rect, sur, 3), calc_surface(rect, sur, 4)};
    int max = 0;
    int index = 0;

    for (int i = 0; i < 4; i++) {
        if (collision[i] > max) {
            max = collision[i];
            index = i;
        }
    }
    return index + 1;
}

//1: left, 2: right, 3:top, 4:bottom
int box_collider_test(dg_entity_t *ent1, dg_entity_t *ent2, int *depth)
{
    sfFloatRect *rect1 = (sfFloatRect *)(dg_entity_get_component(ent1, "box_collider"));
    sfFloatRect *rect2 = (sfFloatRect *)(dg_entity_get_component(ent2, "box_collider"));
    sfFloatRect rect_test = {0};
    sfVector2f *pos1 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));
    sfVector2f *pos2 = (sfVector2f *)(dg_entity_get_component(ent2, "pos"));

    if (!dg_system_require(ent1, 2, "box_collider", "pos") || !dg_system_require(ent2, 2, "box_collider", "pos") || ent1 == ent2)
        return 0;
    if (depth)
        *depth = 0;
    rect1->left += pos1->x;
    rect1->top += pos1->y;
    rect2->left += pos2->x;
    rect2->top += pos2->y;
    if (!sfFloatRect_intersects(rect1, rect2, &rect_test)) {
        absolute_collision(rect1, rect2, pos1, pos2);
        return 0;
    }
    if (rect_test.width < 3 && rect_test.height < 3 ) {
        absolute_collision(rect1, rect2, pos1, pos2);
        return 0;
    }
    if (biggest_surface(*rect1, rect_test) == 1) {
        absolute_collision(rect1, rect2, pos1, pos2);
        if (depth) *depth = rect_test.width;
        return 1;
    }
    if (biggest_surface(*rect1, rect_test) == 2) {
        absolute_collision(rect1, rect2, pos1, pos2);
        if (depth) *depth = -rect_test.width;
        return 2;
    }
    if (biggest_surface(*rect1, rect_test) == 3) {
        absolute_collision(rect1, rect2, pos1, pos2);
        if (depth) *depth = rect_test.height;
        return 3;
    }
    absolute_collision(rect1, rect2, pos1, pos2);
    if (depth) *depth = -rect_test.height;
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
