#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "libdragon.h"
#include "component.h"
#include "rigid_body.h"

static void win_sig(void)
{
    raise(SIGUSR2);
}

static void open_door(dg_entity_t *door, dg_entity_t *key, dg_array_t **entities)
{
    sfSprite *sprite = dg_entity_get_component(door, "sprite");
    dg_spritesheet_t *ss = dg_entity_get_component(door, "spritesheet");
    dg_spritesheet_to_sprite(ss, sprite, 1);
    dg_entity_free_component(door, "box_collider");

    int index = 0;
    void *data = 0;
    dg_array_t *tmp = *entities;

    for (; tmp && tmp->data != key; tmp = tmp->next, index++);
    data = dg_arr_remove_at(entities, index);
    free(data);
}

void sys_win(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    dg_entity_t * tmp = 0;

    (void)dt;
    (void)w;
    if (!strcmp(entity->name, "machine"))
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = (dg_entity_t *) ent->data;
        if (!strcmp(tmp->name, "cog") && box_trigger_box(entity, tmp)) {
            win_sig();
        }
    }
    if (!strcmp(entity->name, "door"))
    for (dg_array_t *ent = *entities; ent; ent = ent->next) {
        tmp = (dg_entity_t *) ent->data;
        if (!strcmp(tmp->name, "key") && box_trigger_box(entity, tmp)) {
            open_door(entity, tmp, entities);;
        }
    }
}
