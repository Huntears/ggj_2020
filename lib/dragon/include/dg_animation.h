/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the spritesheet struct
*/

#ifndef DG_ANIMATION_H_
#define DG_ANIMATION_H_

#include <SFML/Graphics.h>
#include "dg_spritesheet.h"

typedef struct dg_animation
{
    dg_spritesheet_t *sheet;
    int *frames;
    int size;
    float speed;
} dg_animation_t;

dg_animation_t *dg_animation_create(dg_spritesheet_t *, float);

void dg_animation_free(dg_animation_t *);

void dg_animation_add(dg_animation_t *, int);

void dg_animation_update_sprite(dg_animation_t *, sfSprite *, int);

#endif /*DG_ANIMATION_H*/
