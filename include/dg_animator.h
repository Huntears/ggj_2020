/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the animator struct
*/

#ifndef DG_ANIMATOR_H_
#define DG_ANIMATOR_H_

#include <SFML/Graphics.h>
#include "dg_window.h"
#include "dg_animation.h"

typedef struct dg_animator
{
    dg_animation_t **animations;
    char **keys;
    int length;
    int current;
    float time;
} dg_animator_t;

dg_animator_t *dg_animator_create();

void dg_animator_free(dg_animator_t *);

void dg_animator_add(dg_animator_t *, char *name, dg_animation_t *);

void dg_animator_update_sprite(dg_animator_t *, sfSprite *, int);

void dg_animator_set_animation(dg_animator_t *, char *);

#endif /*DG_ANIMATOR_H*/
