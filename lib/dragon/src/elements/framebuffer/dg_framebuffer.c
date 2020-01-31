/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the framebuffer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_framebuffer.h"

//intitialize the framebuffer
dg_framebuffer_t *dg_framebuffer_create(unsigned int width,
    unsigned int height) {
    dg_framebuffer_t *fb = malloc(sizeof(dg_framebuffer_t));
    sfTexture *tex = sfTexture_create(width, height);
    sfSprite *sp = sfSprite_create();

    sfSprite_setTexture(sp, tex, sfFalse);
    fb->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    fb->width = width;
    fb->height = height;
    fb->sp = sp;
    fb->thickness = 1;
    fb->border = 0;
    return fb;
}

//free the framebuffer
int dg_framebuffer_destroy(dg_framebuffer_t *fb)
{
    free(fb->pixels);
    sfTexture_destroy((sfTexture *) sfSprite_getTexture(fb->sp));
    sfSprite_destroy(fb->sp);
    free(fb);
    return 0;
}

//update the framebuffer
void dg_framebuffer_update(dg_framebuffer_t *fb, sfRenderWindow *window)
{
    sfTexture_updateFromPixels((sfTexture *) sfSprite_getTexture(fb->sp),
                               fb->pixels, fb->width, fb->height, 0, 0);
    sfRenderWindow_drawSprite(window, fb->sp, NULL);
}

void set_thickness(dg_framebuffer_t *fb, unsigned int thickness)
{
    fb->thickness = thickness;
}

void set_border(dg_framebuffer_t *fb, unsigned int border)
{
    fb->border = border;
}
