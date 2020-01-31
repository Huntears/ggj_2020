/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the whole lib
*/

#ifndef LIBDRAGON_H_
#define LIBDRAGON_H_

#include <SFML/Graphics.h>
#include "dg_array.h"
#include "dg_framebuffer.h"
#include "dg_window.h"
#include "dg_math.h"
#include "dg_spritesheet.h"
#include "dg_animation.h"
#include "dg_animator.h"
#include "dg_component.h"
#include "dg_entity.h"
#include "dg_system.h"
#include "dg_scene.h"
#include "dg_cpt.h"

int dg_play(unsigned int, unsigned int, char *, int);

#endif
