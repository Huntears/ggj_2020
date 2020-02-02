/*
** EPITECH PROJECT, 2020
** auto_menu
** File description:
** draw_menu
*/

#include "menu_struct.h"

void draw_menu(menu_t *menu)
{
    sfRenderWindow_clear(menu->w, (sfColor){154, 237, 229, 255});
    for (button_t *but = menu->b_list; but != NULL; but = but->next)
        sfRenderWindow_drawText(menu->w, but->text, NULL);
    sfRenderWindow_display(menu->w);
}