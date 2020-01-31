/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** draw a line
*/

#include "dg_framebuffer.h"
#include "dg_math.h"

static int indg_check_spe(dg_framebuffer_t *fb, sfVector2u p1,
                     sfVector2u p2, sfColor color)
{
    unsigned int nb = dg_abs(p1.x - p2.x) + dg_abs(p1.y - p2.y);

    if (fb->thickness == 0)
        return 1;
    if (p1.x == p2.x && p1.y == p2.y) {
        dg_fb_putpx(fb, p1.x, p1.y, color);
        return 1;
    }
    if (nb == 1) {
        dg_fb_putpx(fb, p1.x, p1.y, color);
        dg_fb_putpx(fb, p2.x, p2.y, color);
        return 1;
    }
    return 0;
}

int dg_fb_putline(dg_framebuffer_t *fb, sfVector2u p1, sfVector2u p2,
    sfColor color)
{
    sfVector2u actual = {0, 0};
    unsigned int nb = dg_abs(p1.x - p2.x) + dg_abs(p1.y - p2.y);
    float dx = 0.0;
    float dy = 0.0;

    if (indg_check_spe(fb, p1, p2, color))
        return 0;
    for (int i = 0; i <= nb; i++) {
        dx = ((float)(p2.x) - (float)(p1.x)) / (nb - 1.0) * i;
        dy = ((float)(p2.y) - (float)(p1.y)) / (nb - 1.0) * i;
        actual.x = p1.x + (int)(dx);
        actual.y = p1.y + (int)(dy);
        dg_fb_putsquare(fb, actual, fb->thickness, color);
    }
    return 0;
}
