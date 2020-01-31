
/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_window
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_window.h"

dg_window_t *dg_window_create(
    unsigned int width,
    unsigned int height,
    char *name,
    int id
    )
{
    dg_window_t *window = malloc(sizeof(dg_window_t));
    sfVideoMode mode = {width, height, 32};

    if (!window)
        return 0;
    window->id = id;
    window->window = sfRenderWindow_create(mode, name, sfClose, NULL);
    window->fb = dg_framebuffer_create(mode.width, mode.height);
    return window;
}

void dg_window_destroy(dg_window_t *window)
{
    dg_framebuffer_destroy(window->fb);
    sfRenderWindow_destroy(window->window);
    free(window);
}
