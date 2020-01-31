/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** component animator
*/

#include <stdlib.h>
#include "dg_component.h"
#include "libdragon.h"

static void component_destroy(void *data)
{
    dg_animator_t *animator = (dg_animator_t *)(data);
    dg_animation_t *anim = 0;

    for (int i = 0; i < animator->length; i++) {
        anim = animator->animations[i];
    }
    dg_animator_free(animator);
}

dg_component_t *dg_cpt_animator(dg_animator_t *(*set_animator)(void))
{
    dg_cpt_destroy_t destroy = &component_destroy;
    dg_animator_t *animator = set_animator();
    dg_component_t *component = dg_component_create("animator",
        animator, destroy);

    return component;
}
