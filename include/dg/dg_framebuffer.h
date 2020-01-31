/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the framebuffer struct
*/

#ifndef DG_FRAMEBUFFER_H_
#define DG_FRAMEBUFFER_H_

#include <SFML/Graphics.h>

typedef struct dg_framebuffer
{
    sfUint8 *pixels;
    int width;
    int height;
    sfSprite *sp;
    unsigned int thickness;
    unsigned int border;
} dg_framebuffer_t;

dg_framebuffer_t *dg_framebuffer_create(unsigned int, unsigned int);

int dg_framebuffer_destroy(dg_framebuffer_t *);

void dg_framebuffer_update(dg_framebuffer_t *, sfRenderWindow *);

int dg_fb_putpx(dg_framebuffer_t *, unsigned int, unsigned int, sfColor);

void dg_fb_putsquare(dg_framebuffer_t *, sfVector2u, unsigned int, sfColor);

void dg_fb_putrectangle(dg_framebuffer_t *, sfVector2u, sfVector2u, sfColor);

int dg_fb_putline(dg_framebuffer_t *, sfVector2u, sfVector2u, sfColor);

void dg_fb_putcircle(dg_framebuffer_t *, sfVector2u, unsigned int, sfColor);

#endif
