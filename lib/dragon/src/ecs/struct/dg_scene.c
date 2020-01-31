/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

dg_scene_t *dg_scene_create(void)
{
    dg_scene_t *scene = malloc(sizeof(dg_scene_t));

    if (!scene)
        return 0;
    scene->camera.x = 0;
    scene->camera.y = 0;
    scene->entities = 0;
    scene->systems = 0;
    return scene;
}

void dg_scene_add_ent(dg_scene_t *scene, dg_entity_t *entity)
{
    if (!scene || !entity)
        return;
    dg_arr_add_begin(&(scene->entities), entity);
}

void dg_scene_add_sys(dg_scene_t *scene, dg_system_t *system)
{
    if (!scene || !system)
        return;
    dg_arr_add_begin(&(scene->systems), system);
}

void dg_scene_destroy(dg_scene_t *scene)
{
    dg_array_t *tmp = 0;

    if (!scene)
        return;
    tmp = scene->entities;
    while (tmp) {
        dg_entity_destroy(tmp->data);
        tmp = tmp->next;
    }
    dg_arr_free_all(&(scene->entities));
    tmp = scene->systems;
    while (tmp) {
        dg_system_destroy(tmp->data);
        tmp = tmp->next;
    }
    dg_arr_free_all(&(scene->systems));
    free(scene);
}

void dg_scene_update(dg_scene_t *scene, dg_window_t *w, sfTime dt)
{
    dg_array_t *tmp = 0;
    dg_array_t *sys = 0;
    dg_system_t *vsystem = 0;
    int sp_component = -1;
    sfSprite *sprite = 0;

    if (!scene)
        return;
    for (tmp = scene->entities; tmp; tmp = tmp->next) {
        for (sys = scene->systems; sys; sys = sys->next) {
            vsystem = ((dg_system_t *)(sys->data));
            vsystem->system(tmp->data, w, &(scene->entities),dt);
        }
    }
}

dg_entity_t *dg_get_entity(dg_array_t *entities, char *name)
{
    dg_entity_t *ent = 0;

    if (!entities || !name)
        return 0;
    while (entities && entities->data) {
        ent = ((dg_entity_t *)(entities->data));
        if (!dg_strcmp(ent->name, name))
            return ent;
        entities = entities->next;
    }
    return 0;
}
