#include <stdlib.h>
#include "game.h"
#include "scene.h"
#include "libdragon.h"

typedef struct data {
    dg_scene_t *scene_game;
} data_t;

void *dg_init(dg_window_t *window)
{
    data_t *v = malloc(sizeof(data_t));

    (void)window;
    v->scene_game = scene_game_create();
    return v;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    data_t *v = ((data_t *)(var));

    sfRenderWindow_clear(w->window, sfColor_fromRGB(153, 204, 255));
    dg_scene_update(v->scene_game, w, dt);
    return 0;
}

void dg_end(void *var, int id)
{
    data_t *v = ((data_t *)(var));

    (void)id;
    dg_scene_destroy(v->scene_game);
}

int main(void)
{
    dg_play(1280, 720, "Gamejam 2020", 0);
    return 0;
}
