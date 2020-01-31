/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** manage the general use of the lib
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

typedef struct data {
    dg_scene_t *scene_game;
} data_t;

void *dg_init(dg_window_t *window)
{
    sfVector2f scale = {5, 5};
    data_t *v = malloc(sizeof(data_t));

    v->scene_game = dg_scene_create();
    dg_scene_add_ent(v->scene_game, entity_player_create());
    dg_scene_add_ent(v->scene_game, dg_ent_camera(0, 0));
    dg_scene_add_sys(v->scene_game, dg_system_create(&system_player_control));
    dg_scene_add_sys(v->scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(v->scene_game, dg_system_create(&dg_sys_render));
    return v;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    data_t *v = ((data_t *)(var));

    sfRenderWindow_clear(w->window, sfBlack);
    dg_scene_update(v->scene_game, w, dt);
    return 0;
}

void dg_end(void *var, int id)
{
    data_t *v = ((data_t *)(var));

    dg_scene_destroy(v->scene_game);
}

int main(int argc, char **argv)
{
    dg_play(1920, 1080, "LibDragon", 0);
    return 0;
}
