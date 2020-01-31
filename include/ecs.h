/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the ecs objects
*/

#ifndef ECS_H_
#define ECS_H_

#include "libdragon.h"

dg_entity_t *entity_player_create();

void system_player_control(dg_entity_t *, dg_window_t *, dg_array_t **, sfTime);

#endif
