/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <SFML/Graphics.h>
#include "menu_struct.h"

void draw_menu(menu_t *menu);

int check_button_hitbox(menu_t *menu)
{
    button_t *list = menu->b_list;
    sfVector2f button_pos;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(menu->w);
    int ret = 0;

    for (; list != NULL; list = list->next) {
        button_pos = sfText_getPosition(list->text);
        if (mouse_pos.x >= button_pos.x && mouse_pos.x <= button_pos.x + (list->nb_char * list->size) &&
            mouse_pos.y >= button_pos.y && mouse_pos.y <= button_pos.y + list->size)
                return (list->value);
    }
    return (ret);
}

int get_menu_event(menu_t *menu)
{
    sfEvent evt;
    int ret = 0;

    while (sfRenderWindow_pollEvent(menu->w, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(menu->w);
        if (evt.type == sfEvtMouseButtonPressed && evt.type == evt.mouseButton.button == sfMouseLeft)
            ret = check_button_hitbox(menu);
    }
    return (ret);
}

int menu_loop(menu_t *menu)
{
    int ret = 0;

    ret = get_menu_event(menu);
    draw_menu(menu);
    if (ret == 0)
        menu_loop(menu);
    return (ret);
}