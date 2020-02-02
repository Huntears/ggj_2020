#include <SFML/Audio.h>
#include <stdlib.h>
#include "libdragon.h"

static void component_destroy(void *data)
{
    int *size = (int *)(data);

    free(size);
}

dg_component_t *cpt_roping(int size)
{
    void (*destroy)(void *) = &component_destroy;
    int *cpt = malloc(sizeof(int));

    *cpt = size;
    dg_component_t *component = dg_component_create("roping", cpt, destroy);
    return component;
}
