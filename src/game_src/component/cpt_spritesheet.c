#include <SFML/Audio.h>
#include <stdlib.h>
#include "libdragon.h"

static void component_destroy(void *data)
{
    (void)data;
}

dg_component_t *cpt_spritesheet(dg_spritesheet_t *ss)
{
    void (*destroy)(void *) = &component_destroy;

    dg_component_t *component = dg_component_create("spritesheet", ss, destroy);
    return component;
}
