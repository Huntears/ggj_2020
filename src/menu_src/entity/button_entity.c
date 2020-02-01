/*
** EPITECH PROJECT, 2020
** ggj_2020
** File description:
** button_entity
*/

#include "libdragon.h"
#include "text_cpt.h"

dg_entity_t *create_button_entity(text_t *txt, sfVector2f txt_pos, int click_value)
{
    dg_entity_t *entity = dg_entity_create(txt->string);

    dg_entity_add_component(entity, cpt_value_on_click(click_value));
    dg_entity_add_component(entity, text_cpt(txt, txt_pos));
    return (entity);
}