/*
** EPITECH PROJECT, 2020
** ggj_2020
** File description:
** text_cpt
*/

#include "libdragon.h"
#include "text_cpt.h"

void text_cpt_destroy(sfText *data)
{
    sfText_destroy(data);
}

dg_component_t *text_cpt(text_t *txt, sfVector2f *position)
{
    void (* destroy)(sfText *) = &text_cpt_destroy;
    sfText *text = sfText_create();
    dg_component_t *cpt = NULL;

    if (text == NULL)
        return (NULL);
    sfText_setColor(text, txt->color);
    sfText_setString(text, txt->string);
    sfText_setFont(text, txt->font);
    sfText_setCharacterSize(text, txt->size);
    sfText_setOutlineThickness(text, txt->thickness);
    cpt = dg_component_create("text", text, destroy);
    return (cpt);
}