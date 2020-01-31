/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the spritesheet struct
*/

#ifndef DG_SPRITESHEET_H_
#define DG_SPRITESHEET_H_

#include <SFML/Graphics.h>

typedef struct dg_spritesheet
{
    sfTexture *sheet;
    unsigned int x;
    unsigned int y;
} dg_spritesheet_t;

dg_spritesheet_t *dg_spritesheet_create(char *, int, int);

void dg_spritesheet_free(dg_spritesheet_t *);

void dg_spritesheet_to_sprite(dg_spritesheet_t *, sfSprite *, int);

#endif /*DG_SPRITESHEET_H_*/
