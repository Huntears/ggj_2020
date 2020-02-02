//Auteur : Alexia
//catchable component

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"
#include "rigid_body.h"

static void component_destroy(void *data)
{
    (void)data;
    return;
}

dg_component_t *cpt_catchable(void)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    dg_component_t *component = dg_component_create("catchable", NULL, destroy);

    if (!component) {
        dprintf(2, "Error: catchable not created.\n");
        return 0;
    }
    return component;
}
