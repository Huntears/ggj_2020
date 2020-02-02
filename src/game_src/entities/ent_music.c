/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** music entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "component.h"

dg_entity_t *ent_music(char *path)
{
    dg_entity_t *entity = dg_entity_create("music");

    dg_entity_add_component(entity, cpt_music(path));
    return entity;
}
