/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the whole lib
*/

#ifndef LIBDRAGON_H_
#define LIBDRAGON_H_

#include <SFML/Graphics.h>
#include "dg/dg_array.h"
#include "dg/dg_framebuffer.h"
#include "dg/dg_window.h"
#include "dg/dg_math.h"
#include "dg/dg_spritesheet.h"
#include "dg/dg_animation.h"
#include "dg/dg_animator.h"
#include "dg/dg_component.h"
#include "dg/dg_entity.h"
#include "dg/dg_system.h"
#include "dg/dg_scene.h"
#include "dg/dg_cpt.h"

int dg_play(unsigned int, unsigned int, char *, int);

#endif
