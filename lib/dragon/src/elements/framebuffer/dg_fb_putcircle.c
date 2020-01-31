/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** draw a circle in a framebuffer
*/

#include "dg_framebuffer.h"
#include "dg_math.h"

static void ingd_circle(dg_framebuffer_t *fb, int *coord, sfColor color)
{
    int x = coord[0] - coord[4];
    int y = coord[1] - coord[4];

    if (dg_square(x) + dg_square(y) <= dg_square(coord[4]))
        dg_fb_putpx(fb, x + coord[2], y + coord[3], color);
}

void dg_fb_putcircle(dg_framebuffer_t *fb, sfVector2u pos, unsigned int radius,
    sfColor color)
{
    int coord[5] = {0, 0, pos.x, pos.y, radius};

    for (int x = 0; x < radius * 2; x++)
        for (int y = 0; y < radius * 2; y++) {
            coord[0] = x;
            coord[1] = y;
            ingd_circle(fb, coord, color);
        }
}
