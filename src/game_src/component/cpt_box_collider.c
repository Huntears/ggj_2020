//Auteur : Alexia
//Box collider (collision rectangulaire)

#include <stdlib.h>
#include "libdragon.h"

//1: left, 2: right, 3:top, 4:bottom
int box_collider_test(dg_entity_t *ent1, dg_entity_t *ent2)
{
    int stat = 0;
    sfFloatRect *rect1 = (sfFloatRect *)(dg_entity_get_component(ent1, "box_collider"));
    sfFloatRect *rect2 = (sfFloatRect *)(dg_entity_get_component(ent2, "box_collider"));
    sfFloatRect rect_test = 0;
    sfVector2f *pos1 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));
    sfVector2f *pos2 = (sfVector2f *)(dg_entity_get_component(ent1, "pos"));

    rect1->left += pos1.x;
    rect1->top +=
    if (!dg_system_require(ent1, 2, "box_collider", "pos") || !dg_system_require(ent2, 2, "box_collider", "pos"))
        return 0;
    if (!sfFloatRect_intersects(rect1, rect2, &rect_test))
        return 0;
    if (rect_test.left <= rect1->left)
        return 1;
    if (rect_test.left + rect_test.width >= rect1->left + rect1->width)
        return 2;
    if (rect_test.top <= rect1->top)
        return 3;
    return 4;
}

static void component_destroy(void *data)
{
    dg_animator_t *animator = (dg_animator_t *)(data);

    for (int i = 0; i < animator->length; i++) {
        anim = animator->animations[i];
    }
    dg_animator_free(animator);
}

dg_component_t *cpt_box_collider(float x, float y, float width, float height)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfFloatRect *box_collider = malloc(sizeof(sfFloatRect));
    dg_component_t *component = dg_component_create("box_collider",
        box_collider, destroy);

    if (!box_collider || !component) {
        printf("Error: box_collider not created.\n");
        return 0;
    }
    box_collider->left = x;
    box_collider->top = y;
    box_collider->width = width;
    box_collider->height = height;
    return component;
}
