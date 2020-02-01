//Auteur : Alexia
//Rigid body (gravity)

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"
#include "rigid_body.h"

static void component_destroy(void *data)
{
    rigid_body_t *rb = (rigid_body_t *)(data);

    free(rb);
}

dg_component_t *cpt_rigid_body(float gravity, float mass)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    rigid_body_t *rb = rb_create(gravity, mass);
    dg_component_t *component = dg_component_create("rigid_body", rb, destroy);

    if (!rb || !component) {
        dprintf(2, "Error: rigid_body not created.\n");
        return 0;
    }
    return component;
}
