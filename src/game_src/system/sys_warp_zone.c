#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "libdragon.h"
#include "component.h"

static void teleport_time(void)
{
    static int released = 0;

    if (!sfKeyboard_isKeyPressed(sfKeyE))
        released = 0;
    else if (!released) {
        released = 1;
        raise(SIGUSR1);
    }
}

void sys_warp_zone(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    dg_entity_t * tmp = 0;

    (void)dt;
    (void)w;
    if (strcmp(entity->name, "player"))
        return;
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = (dg_entity_t *) ent->data;
        if (!strcmp(tmp->name, "warp_place") && box_trigger_box(entity, tmp)) {
            teleport_time();
        }
    }
}
