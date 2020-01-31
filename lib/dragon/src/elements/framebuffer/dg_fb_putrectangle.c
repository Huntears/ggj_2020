/*
** EPITECH PROJECT, 2019
** draw a square
** File description:
** draw rectangles
*/

#include "dg_framebuffer.h"

void dg_fb_putsquare(dg_framebuffer_t *fb, sfVector2u position,
    unsigned int size, sfColor color)
{
    for (int i = position.x; i < position.x + size; i++)
        for (int j = position.y; j < position.y + size; j++)
            dg_fb_putpx(fb, i, j, color);
}

//draw a rectangle
void dg_fb_putrectangle(dg_framebuffer_t *fb, sfVector2u position,
    sfVector2u size, sfColor color)
{
    for (int i = position.x; i < position.x + size.x; i++)
        for (int j = position.y; j < position.y + size.y; j++)
            dg_fb_putpx(fb, i, j, color);
}

