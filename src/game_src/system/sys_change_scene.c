#include <stdlib.h>
#include <signal.h>
#include "libdragon.h"

void sys_change_scene(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    (void)entity;
    (void)w;
    (void)entities;
    (void)dt;
    static int released = 0;

    if (!sfKeyboard_isKeyPressed(sfKeySpace))
        released = 0;
    else if (!released) {
        released = 1;
        raise(SIGUSR1);
    }
}