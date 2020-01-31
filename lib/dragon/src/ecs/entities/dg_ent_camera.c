/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** camera entity and system
*/

#include <stdlib.h>
#include "libdragon.h"

dg_entity_t *dg_ent_camera(int x, int y)
{
    dg_entity_t *entity = dg_entity_create("camera");

    dg_entity_add_component(entity, dg_cpt_pos(x, y));
    return entity;
}
