/*
** EPITECH PROJECT, 2020
** auto_menu
** File description:
** menu_creation
*/

#include <SFML/Graphics.h>
#include "menu_struct.h"
#include <stdlib.h>
#include <string.h>

void create_clickable_text(menu_t *menu, fast_button_t info, sfVector2f pos)
{
    button_t *last = menu->b_list;
    button_t *new = malloc(sizeof(struct button));

    sfText *text = sfText_create();
    sfText_setString(text, info.name);
    sfText_setCharacterSize(text, info.size);
    sfText_setFont(text, info.font);
    sfText_setOutlineThickness(text, info.thickness);
    sfText_setColor(text, info.color);
    sfText_setPosition(text, pos);
    new->value = info.value;
    new->text = text;
    new->size = info.size;
    new->nb_char = strlen(info.name);
    if (last == NULL) {
        menu->b_list = new;
        menu->b_list->next = NULL;
        return;
    }
    for (; last->next != NULL; last = last->next);
    last->next = new;
    new->next = NULL;
}

menu_t *load_menu(sfRenderWindow *window)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->status = 0;
    menu->font = sfFont_createFromFile("font/menu.ttf");
    menu->b_list = NULL;
    menu->w = window;
    create_clickable_text(menu, (fast_button_t){"bob.ReparerLeTemps()", 0, 64, menu->font, sfBlack, 1}, (sfVector2f){300, 150});
    create_clickable_text(menu, (fast_button_t){"Jouer", 1, 43, menu->font, sfWhite, 1}, (sfVector2f){550, 300});
    create_clickable_text(menu, (fast_button_t){"Quitter", -1, 43, menu->font, sfWhite, 1}, (sfVector2f){530, 450});
    return (menu);
}