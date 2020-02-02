/*
** EPITECH PROJECT, 2020
** auto_menu
** File description:
** menu_struct
*/

#ifndef MENU_STRUCT_H_
#define MENU_STRUCT_H_

#include <SFML/Graphics.h>

typedef struct button {
    sfText *text;
    sfVector2f pos;
    int size;
    short value;
    short nb_char;
    struct button *next;
}button_t;

typedef struct menu {
    sfRenderWindow *w;
    button_t *b_list;
    sfFont *font;
    int status;
}menu_t;

typedef struct auto_menu {
    char *name;
    short value;
    int size;
    sfFont *font;
    sfColor color;
    float thickness;
}fast_button_t;

void add_menu_button(menu_t *, fast_button_t, sfVector2f);
int menu_loop(menu_t *menu);
menu_t *load_menu(sfRenderWindow *window);

#endif /* !MENU_STRUCT_H_ */