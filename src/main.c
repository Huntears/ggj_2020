#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "game.h"
#include "scene.h"
#include "entity.h"
#include "libdragon.h"

typedef struct data {
    dg_scene_t *scene_game;
    dg_scene_t *scene_past;
} data_t;

static int scene_id = 0;

static void change_scene(int dummy)
{
    (void)dummy;
    scene_id = (scene_id) ? 0 : 1;
}

void *dg_init(dg_window_t *window)
{
    data_t *v = malloc(sizeof(data_t));

    signal(SIGUSR1, change_scene);
    (void)window;
    v->scene_game = scene_game_create();
    v->scene_past = scene_past_create();
    return v;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    data_t *v = ((data_t *)(var));

    sfRenderWindow_clear(w->window, sfColor_fromRGB(153, 204, 255));
    if (scene_id == 0)
        dg_scene_update(v->scene_game, w, dt);
    else
        dg_scene_update(v->scene_past, w, dt);
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        dg_entity_t *camera = dg_get_entity(v->scene_game->entities, "camera");
        sfVector2f *pos = dg_entity_get_component(camera, "pos");
        dg_entity_t *camera2 = dg_get_entity(v->scene_past->entities, "camera");
        sfVector2f *pos2 = dg_entity_get_component(camera2, "pos");
        dg_scene_adde_ent(v->scene_game, ent_furret(pos->x, pos->y));
        dg_scene_adde_ent(v->scene_past, ent_furret(pos2->x, pos2->y));
    }
    return 0;
}

void dg_end(void *var, int id)
{
    data_t *v = ((data_t *)(var));

    (void)id;
    dg_scene_destroy(v->scene_game);
    dg_scene_destroy(v->scene_past);
}

int main(void)
{
    dg_play(1280, 720, "Gamejam 2020", 0);
    return 0;
}
