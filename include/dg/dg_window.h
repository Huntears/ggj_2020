/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_window struct
*/

#ifndef DG_WINDOW_H_
#define DG_WINDOW_H_

#include <SFML/Graphics.h>
#include "dg_framebuffer.h"

typedef struct dg_window
{
    sfRenderWindow *window;
    dg_framebuffer_t *fb;
    int id;

} dg_window_t;

dg_window_t *dg_window_create(unsigned int, unsigned int, char *, int);

void dg_window_destroy(dg_window_t *);

#endif /*DG_WINDOW_H*/
