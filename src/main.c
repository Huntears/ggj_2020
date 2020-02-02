#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "game.h"
#include "scene.h"
#include "entity.h"
#include "libdragon.h"
#include "rigid_body.h"

typedef struct data {
    dg_scene_t *scene_game;
    dg_scene_t *scene_past;
    sfVector2f player_pos;
    sfVector2f player_strengh;
} data_t;



static int scene_id = 0;

static int stat = 0;

static int level = 0;

static dg_scene_t *(*present[1])(void) = {&scene_game_create};

static dg_scene_t *(*past[1])(void) = {&scene_past_create};

static void change_scene(int dummy)
{
    (void)dummy;
    stat = 0;
    scene_id = (scene_id) ? 0 : 1;
}

static void win_and_change(int dummy)
{
    (void)dummy;
    stat = -1;
    level++;
}

static void add_furret(data_t *v)
{
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        dg_entity_t *camera = dg_get_entity(v->scene_game->entities, "camera");
        sfVector2f *pos = dg_entity_get_component(camera, "pos");
        dg_entity_t *camera2 = dg_get_entity(v->scene_past->entities, "camera");
        sfVector2f *pos2 = dg_entity_get_component(camera2, "pos");
        dg_scene_adde_ent(v->scene_game, ent_furret(pos->x, pos->y));
        dg_scene_adde_ent(v->scene_past, ent_furret(pos2->x, pos2->y));
    }
}

static void get_time_cpt(dg_scene_t *scene, data_t *v)
{
    dg_entity_t *player = dg_get_entity(scene->entities, "player");

    if (player) {
        sfVector2f *p_pos = dg_entity_get_component(player, "pos");
        v->player_pos = (sfVector2f){p_pos->x, p_pos->y};
        rigid_body_t *p_str = dg_entity_get_component(player, "rigid_body");
        v->player_strengh = (sfVector2f){p_str->strengh.x, p_str->strengh.y};
    }
}

static void set_time_cpt(dg_scene_t *scene, data_t *v)
{
    dg_entity_t *player = dg_get_entity(scene->entities, "player");

    if (player) {
        sfVector2f *p_pos = dg_entity_get_component(player, "pos");
        p_pos->x = v->player_pos.x;
        p_pos->y = v->player_pos.y;
        rigid_body_t *p_str = dg_entity_get_component(player, "rigid_body");
        p_str->strengh.x = v->player_strengh.x;
        p_str->strengh.y = v->player_strengh.y;
    }
}

void *dg_init(dg_window_t *window)
{
    data_t *v = malloc(sizeof(data_t));

    signal(SIGUSR1, change_scene);
    signal(SIGUSR2, win_and_change);
    (void)window;
    v->scene_game = present[0]();
    v->scene_past = past[0]();
    v->player_pos = (sfVector2f){64,96};
    return v;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    data_t *v = ((data_t *)(var));

    sfRenderWindow_clear(w->window, sfColor_fromRGB(153, 204, 255));

    if (stat >= 0) {
        if (scene_id == 0) {
            if (stat)
                get_time_cpt(v->scene_game, v);
            else {
                stat = 1;
                set_time_cpt(v->scene_game, v);
            }
            dg_scene_update(v->scene_game, w, dt);
        }
        else {
            if (stat)
                get_time_cpt(v->scene_past, v);
            else {
                stat = 1;
                set_time_cpt(v->scene_past, v);
            }
            dg_scene_update(v->scene_past, w, dt);
        }
        add_furret(v);
    } else {
        stat = 1;
        dg_scene_destroy(v->scene_game);
        dg_scene_destroy(v->scene_past);
        v->scene_game = 0;
        v->scene_past = 0;
    }
    return 0;
}

void dg_end(void *var, int id)
{
    data_t *v = ((data_t *)(var));

    (void)id;
    if (v->scene_game)
        dg_scene_destroy(v->scene_game);
    if (v->scene_past)
        dg_scene_destroy(v->scene_past);
}

int main(void)
{
    dg_play(1280, 720, "bob.changerLeTemps()", 0);
    return 0;
}
